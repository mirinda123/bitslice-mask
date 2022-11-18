	.syntax unified
	.cpu cortex-m4
	.set ORDER, 2
	.set WIDTHBYTE, 4

	
	
.macro matrosecxor_ xlabel, ylabel, zlabel, kvalue, precomp
		LDR r6, =\xlabel
		LDR r7, =\ylabel
		LDR r11, =\zlabel
	//	matrosecxor xaddr, yaddr, txaddr, tyaddr, traddr, zaddr, temp1, temp2, temp3, kvalue, precomp
		matrosecxor r6   , r7   , r8    , r9    , r10   , r11  , r0   , r1   , r2   , \kvalue, \precomp
		.ltorg
.endm


.macro matrosecxor xaddr, yaddr, txaddr, tyaddr, traddr, zaddr, temp1, temp2, temp3, kvalue, precomp
		.if \kvalue == 1
			LDR \temp1, [\xaddr]
			LDR \temp2, [\yaddr]
			EOR  \temp1, \temp1, \temp2
			
			//zaddr[0] = xaddr[0] xor yaddr[0]
			STR \temp1, [\zaddr]
			.exitm
		.endif
		.if \kvalue > 1
			.if \precomp==1
				matrosecxor \xaddr, \yaddr, \txaddr, \tyaddr, \traddr, \zaddr, \temp1, \temp2, \temp3, \kvalue-1, \precomp
			.endif
				
			//temp1 = xaddr[k-1]
			//temp2 = yaddr[k-1]
			LDR \temp1, [\xaddr,#(\kvalue-1)*WIDTHBYTE*\precomp]
			LDR \temp2, [\yaddr,#(\kvalue-1)*WIDTHBYTE*\precomp]
			
			// \temp1 =  xaddr[] xor yaddr[]
			EOR  \temp1, \temp1, \temp2
			
			// STRH R0,[R1]         R0 to [R1]
			//zaddr[k-1] = xaddr[k-1] xor yaddr[k-1]
			STR \temp1, [\zaddr,#(\kvalue-1)*WIDTHBYTE*\precomp]
		.endif
.endm

.macro matrosecandnew_ oxlabel, oylabel, xlabel, ylabel, zlabel, trlabel, kvalue, precomp,randomtable,flag
	LDR r6, =\oxlabel
	.ltorg
	LDR r7, =\oylabel
	.ltorg
	LDR r11, =\zlabel
	.ltorg
	LDR r8, =\xlabel
	.ltorg
	LDR r9, =\ylabel
	.ltorg
	LDR r10, =\trlabel
	.ltorg
//  matrosecandnew oxaddr, oyaddr, xaddr, xaddr, traddr, zaddr, temp1, temp2, temp3, x  , y , z , kvalue , precomp , randomtableaddr, flag
	matrosecandnew r6    , r7    , r8   , r9   , r10   , r11  , r0   , r1   , r2   , r3 , r4, r5, \kvalue, \precomp, \randomtable   , \flag
	.ltorg
.endm

.macro matrosecandnew oxaddr, oyaddr, xaddr, yaddr, traddr, zaddr, temp1, temp2, temp3, x, y, z, kvalue, precomp,randomtableaddr,flag
		.if \kvalue == 1 
			
			MOV \temp1, #0
			MOV \temp2 ,#0
			//temp1 = xaddr[0]
			LDR \temp1, [\xaddr]
			// temp2 = yaddr[0]
			LDR \temp2, [\yaddr]
			//temp1 = xaddr[0]yaddr[0]
			AND  \temp1, \temp2
			
			// zaddr 是论文中的u
			//when k == 1
			// zaddr[0] = xaddr[0]yaddr[0]
			STR \temp1, [\zaddr]
			.set ii, 0
				
			//如果是初始order为1(flag == 1)，应该会有一个额外的情况
			//即precompute后面的那些步骤
			.if \flag == 1 && \precomp == 1
				//temp3: 随机数
				LDR \temp3, [\randomtableaddr], #4 //random bits
				// temp2 = zaddr[ii]即ui
				LDR \temp2, [\zaddr,#ii]
				//更新z为随机数
				STR \temp3, [\zaddr,#ii]
				// temp2 = r xor zaddr[ii]
				EOR  \temp2, \temp3
				// traddr[ii] = r xor  zaddr[ii]
				STR \temp2, [\traddr,#ii]
			.endif
				
			// exit  macro
			.exitm
		.endif
		.if \kvalue > 1
			// 如果是online计算，不会进入递归
			.if \precomp==1
				matrosecandnew \oxaddr, \oyaddr, \xaddr, \yaddr, \traddr, \zaddr, \temp1, \temp2, \temp3, \x, \y, \z, \kvalue-1, \precomp,\randomtableaddr,\flag
			.endif
				
			
			//when k=2
			//x = xaddr[1] y = yaddr[1]
			
			//when k=4
			//x == xaddr[3] y= yaddr[3]
			//[\xaddr,#(\kvalue-1)*\precomp] 对应于xk
			
			//如果是在线计算，取的是xaddr[0] , yaddr[0]
			MOV \z, #0
			MOV \x, #0
			MOV \y, #0
			LDR \x, [\oxaddr,#(\kvalue-1)*WIDTHBYTE*\precomp]
			LDR \y, [\oyaddr,#(\kvalue-1)*WIDTHBYTE*\precomp]
			
			//z : xy
			//用于第12行
			//如果是online计算，z是论文中的 xk+1 yk+1
			AND  \z, \x, \y
			
			
			//----------------------------------------
			
			//如果是online计算，不会用随机数
			.if \precomp == 1
				.set ii, 0
				// 计算tr
				.rept  \kvalue-1
					//temp3 = r[i]
					LDR \temp3, [\randomtableaddr], #4 //random bits
					// temp2 = u[i]
					LDR \temp2, [\zaddr,#ii]
					//更新z为新生成的k-1个随机数
					STR \temp3, [\zaddr,#ii]
					// temp2 = r[i] xor u[i]
					EOR  \temp2, \temp3
					// traddr[ii] = r[i] xor  u[i]
					STR \temp2, [\traddr,#ii]
					.set ii, ii+1 * WIDTHBYTE
				.endr
				
			.endif
			
			.set ii, 0
			// repeat \kvalue-1 times
			// 下面这个循环是算zk+1
			.rept  \kvalue-1
				MOV \temp1, #0
				MOV \temp2, #0
				//temp1 = xaddr[ii]
				LDR \temp1, [\xaddr,#ii]
				// temp2 = traddr[ii]
				LDR \temp2, [\traddr,#ii]
				
				EOR \temp1, \temp2
				AND \temp1, \y

				MVN \y, \y
				AND \temp2, \y
				EOR \temp2, \temp1
				MVN \y, \y
				MOV \temp1, #0
				LDR \temp1, [\yaddr, #ii]
				EOR \temp1, \temp2
				AND \temp1, \x
				MVN \x, \x
				AND \temp2, \x
				EOR \temp2, \temp1
				MVN \x, \x
				EOR \z, \temp2
				// ii ++ 
				.set ii, ii+1 * WIDTHBYTE
			.endr
			
			//----------------------------------------
			
			// store z[k-1] = z
			// 计算好第k个z，即第k个u
			// 注意，计算出来第k个z后，之前的z都会变成随机数
			STR \z, [\zaddr,#(\kvalue-1)*WIDTHBYTE*\precomp]
			
			//末尾的一小段
			// 这一小段会把z1-zd变成随机数
			.if \kvalue == ORDER && \precomp == 1
				//进入之前，算出了u1...ud ,即z1...zd
				.set ii, 0
				//这里是不是要多一次
				.rept  \kvalue
					//temp3 = r
					LDR \temp3, [\randomtableaddr], #4 //random bits
					// temp2 = zaddr[ii]
					LDR \temp2, [\zaddr,#ii]
					//更新z为随机数
					STR \temp3, [\zaddr,#ii]
					// temp2 = r xor zaddr[ii]
					EOR  \temp2, \temp3
					// traddr[ii] = r xor  zaddr[ii]
					STR \temp2, [\traddr,#ii]
					// ii ++ 
					.set ii, ii+1 * WIDTHBYTE
				.endr
				.exitm
			.endif
		.endif
	.endm
	
.macro STOREBACK sbs, online_sbs, sbx, online_sbx, kvalue
	LDR r4, =\sbs
	LDR r5, =\online_sbs
	
	LDR r6, =\sbx
	LDR r7, =\online_sbx
	
	.set ii, 0
	.rept  \kvalue
		// r8 used as temp
		MOV r8, 0
		LDR r8, [r4, #ii]
		STR r8, [r6, #ii]
		.set ii, ii+1 * WIDTHBYTE
	.endr
	MOV r8, 0
	LDR r8, [r5]
	STR r8, [r7]
.endm



.macro duplicate src, dst, kvalue
	LDR r4, =\src
	LDR r5, =\dst
		
	.set ii, 0
	.rept  \kvalue
		// r8 used as temp
		MOV r8, 0
		LDR r8, [r4, #ii]
		STR r8, [r5, #ii]
		.set ii, ii+1 * WIDTHBYTE
	.endr
.endm
	
	
	.global sbox_test
	.global sboxprecom
	.global sboxonline
	.section .text
	.align 4
	
sbox_test:
	// 单个and是没有问题的，但是matrosecandnew_ sby12,sby15,sby12, sby15, sbt2,sband1tr, ORDER, 1,r12,ORDER 就有问题了....
	// 难道有多个and 会出问题吗？没有问题
	
	
	LDR r12, =random_table
	matrosecandnew_ sbxtest,sbytest,sbxtest, sbytest, sbttest,sband0trtest, ORDER, 1,r12,ORDER
	matrosecandnew_ sbctest,sbdtest,sbctest, sbdtest, sbetest,sband1trtest, ORDER, 1,r12,ORDER
	
	matrosecandnew_ online_sbxtest, online_sbytest, sbxtest,sbytest,online_sbttest, sband0trtest, ORDER + 1, 0,r12,ORDER
	matrosecandnew_ online_sbctest, online_sbdtest, sbctest,sbdtest,online_sbetest, sband1trtest, ORDER + 1, 0,r12,ORDER
	
	bx lr
sboxprecom:
	
	PUSH {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
	
	//x0 = q[7];
	//x1 = q[6];
	//x2 = q[5];
	//x3 = q[4];
	//x4 = q[3];
	//x5 = q[2];
	//x6 = q[1];
	//x7 = q[0];
	
	//因为预计算后，经过shiftrow和mixcolumn，sbx会改变，影响sboxonline的计算，所以把初始的sbx都暂存起来
	duplicate sbx7, sbx7_for_online, ORDER
	
	//这边的输入检查过了，没有问题x0-x7是对的
	matrosecxor_ sbx3, sbx5, sby14, ORDER, 1
	matrosecxor_ sbx0, sbx6, sby13, ORDER, 1
	matrosecxor_ sby13, sby14, sby12, ORDER, 1
	matrosecxor_ sbx0, sbx3, sby9, ORDER, 1
	matrosecxor_ sbx0, sbx5, sby8, ORDER, 1
	matrosecxor_ sbx1, sbx2, sbt0, ORDER, 1
	matrosecxor_ sbt0, sbx7, sby1, ORDER, 1
	matrosecxor_ sby1, sbx3, sby4, ORDER, 1
	matrosecxor_ sby1, sbx0, sby2, ORDER, 1
	matrosecxor_ sby1, sbx6, sby5, ORDER, 1
	matrosecxor_ sbx4, sby12, sbt1, ORDER, 1
	matrosecxor_ sby5, sby8, sby3, ORDER, 1
	matrosecxor_ sbt1, sbx5, sby15, ORDER, 1
	matrosecxor_ sbt1, sbx1, sby20, ORDER, 1
	matrosecxor_ sby15, sbx7, sby6, ORDER, 1
	matrosecxor_ sby15, sbt0, sby10, ORDER, 1
	matrosecxor_ sby20, sby9, sby11, ORDER, 1
	
	
	matrosecxor_ sbx7, sby11, sby7, ORDER, 1
	matrosecxor_ sby10, sby11, sby17, ORDER, 1
	matrosecxor_ sby10, sby8, sby19, ORDER, 1
	matrosecxor_ sbt0, sby11, sby16, ORDER, 1
	matrosecxor_ sby13, sby16, sby21, ORDER, 1
	matrosecxor_ sbx0, sby16, sby18, ORDER, 1
///////////////////////////////////////////////////////////////////////////////
	LDR r12, =random_table
	

	matrosecandnew_ sby12,sby15,sby12, sby15, sbt2,sband1tr, ORDER, 1,r12,ORDER
	
	//经过验证，到这里没有问题，t2异或起来是正确的
	matrosecandnew_ sby3,sby6,sby3, sby6, sbt3, sband2tr, ORDER, 1,r12,ORDER
	
	//t3也是正确的
	matrosecandnew_ sby4,sbx7,sby4, sbx7, sbt5, sband3tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sby13,sby16,sby13, sby16, sbt7, sband4tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sby5,sby1,sby5, sby1, sbt8, sband5tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sby2,sby7,sby2, sby7, sbt10,sband6tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sby9, sby11,sby9,sby11,sbt12,sband7tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sby14, sby17, sby14, sby17,sbt13,sband8tr, ORDER, 1,r12,ORDER
	matrosecxor_ sbt3, sbt2, sbt4, ORDER, 1
	matrosecxor_ sbt5, sbt2, sbt6, ORDER, 1
	matrosecxor_ sbt8, sbt7, sbt9, ORDER, 1
	matrosecxor_ sbt10, sbt7, sbt11, ORDER, 1
	matrosecxor_ sbt13, sbt12, sbt14, ORDER, 1
	matrosecxor_ sbt4, sbt14, sbt17, ORDER, 1
	matrosecxor_ sbt9, sbt14, sbt19, ORDER, 1
	matrosecxor_ sbt17, sby20, sbt21, ORDER, 1
	matrosecxor_ sbt19, sby21, sbt23, ORDER, 1
	matrosecandnew_ sby8, sby10, sby8, sby10,sbt15,sband9tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sbt21, sbt23,sbt21, sbt23, sbt26, sband10tr, ORDER, 1,r12,ORDER
	

	matrosecxor_ sbt15, sbt12, sbt16, ORDER, 1
	matrosecxor_ sbt6, sbt16, sbt18, ORDER, 1
	matrosecxor_ sbt11, sbt16, sbt20, ORDER, 1
	matrosecxor_ sbt20, sby18, sbt24, ORDER, 1
	matrosecxor_ sbt23, sbt24, sbt30, ORDER, 1
	matrosecxor_ sbt18, sby19, sbt22, ORDER, 1
	matrosecxor_ sbt21, sbt22, sbt25, ORDER, 1
	matrosecxor_ sbt24, sbt26, sbt27, ORDER, 1
	matrosecxor_ sbt22, sbt26, sbt31, ORDER, 1
	matrosecandnew_ sbt25, sbt27, sbt25, sbt27,sbt28, sband11tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sbt31, sbt30, sbt31, sbt30,sbt32, sband12tr, ORDER, 1,r12,ORDER
	matrosecxor_ sbt28, sbt22, sbt29, ORDER, 1
	//https://eprint.iacr.org/2016/264.pdf 这里写错了
	matrosecxor_ sbt32, sbt24, sbt33, ORDER, 1
	matrosecxor_ sbt23, sbt33, sbt34, ORDER, 1
	matrosecxor_ sbt27, sbt33, sbt35, ORDER, 1
	matrosecxor_ sbt29, sbt33, sbt42, ORDER, 1
	matrosecandnew_ sbt29, sby2, sbt29, sby2,sbz14, sband13tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sbt24, sbt35, sbt24, sbt35,sbt36,sband14tr, ORDER, 1,r12,ORDER
	matrosecxor_ sbt36, sbt34, sbt37, ORDER, 1
	matrosecxor_ sbt27, sbt36, sbt38, ORDER, 1
	matrosecandnew_ sbt29, sbt38, sbt29, sbt38,sbt39, sband15tr, ORDER, 1,r12,ORDER
	matrosecandnew_ sbt29, sby7, sbt29, sby7,sbz5, sband16tr, ORDER, 1,r12,ORDER
	matrosecxor_ sbt33, sbt37, sbt44, ORDER, 1
	matrosecxor_ sbt25, sbt39, sbt40, ORDER, 1
	matrosecxor_ sbt40, sbt37, sbt41, ORDER, 1
	matrosecxor_ sbt29, sbt40, sbt43, ORDER, 1
	matrosecxor_ sbt42, sbt41, sbt45, ORDER, 1
	matrosecandnew_ sbt44, sby15,sbt44, sby15, sbz0, sband17tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt37, sby6, sbt37, sby6, sbz1, sband18tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt33, sbx7, sbt33, sbx7, sbz2, sband19tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt43, sby16, sbt43, sby16, sbz3, sband20tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt40, sby1, sbt40, sby1, sbz4, sband21tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt42, sby11, sbt42, sby11, sbz6, sband22tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt45, sby17, sbt45, sby17, sbz7, sband23tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt41, sby10, sbt41, sby10, sbz8, sband24tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt44, sby12, sbt44, sby12, sbz9, sband25tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt37, sby3, sbt37, sby3, sbz10, sband26tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt33, sby4, sbt33, sby4, sbz11, sband27tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt43, sby13, sbt43, sby13, sbz12, sband28tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt40, sby5, sbt40, sby5, sbz13, sband29tr, ORDER, 1, r12, ORDER
	matrosecandnew_ sbt42, sby9, sbt42, sby9, sbz15, sband30tr, ORDER, 1,r12, ORDER
	matrosecandnew_ sbt45, sby14, sbt45, sby14, sbz16, sband31tr, ORDER, 1,r12, ORDER
	matrosecandnew_ sbt41, sby8, sbt41, sby8, sbz17, sband32tr, ORDER, 1,r12, ORDER
//////////////////////////////////////////////////////////////////////////////////////////////
	matrosecxor_ sbz15, sbz16, sbt46, ORDER, 1
	matrosecxor_ sbz16, sbz17, sbt55, ORDER, 1
	matrosecxor_ sbz7, sbz8, sbt52, ORDER, 1
	matrosecxor_ sbz6, sbz7, sbt54, ORDER, 1
	matrosecxor_ sbz4, sbt46, sbt58, ORDER, 1
	matrosecxor_ sbz3, sbt54, sbt59, ORDER, 1
	matrosecxor_ sbz4, sbt59, sbt64, ORDER, 1
	matrosecxor_ sbz10, sbz11, sbt47, ORDER, 1
	matrosecxor_ sbz9, sbz10, sbt49, ORDER, 1
	matrosecxor_ sbt49, sbt58, sbt63,ORDER, 1
	matrosecxor_ sbz1, sbt63, sbt66, ORDER, 1
	matrosecxor_ sbt52, sbt58, sbt62, ORDER, 1
	matrosecxor_ sbz0, sbz3, sbt53, ORDER, 1
	matrosecxor_ sbz2, sbz12, sbt50, ORDER, 1
	matrosecxor_ sbt50, sbt53, sbt57, ORDER, 1
	//这里有错
	matrosecxor_ sbt46, sbt57, sbt60, ORDER, 1
	matrosecxor_ sbz14, sbt57, sbt61, ORDER, 1
	matrosecxor_ sbt61, sbt62, sbt65, ORDER, 1
	
	
	matrosecxor_ sbt59, sbt63, sbs0,ORDER, 1
	matrosecxor_ sbz2, sbz5, sbt51, ORDER, 1
	matrosecxor_ sbt51, sbt66, sbs4, ORDER, 1
	matrosecxor_ sbt47, sbt65, sbs5, ORDER, 1
	matrosecxor_ sbt64, sbt65, sbt67, ORDER, 1
	// 这里不能这么写，这样写，sbx2就被修改过了，但是下面的online部分需要！明天重新改一下
	matrosecxor_ sbt55, sbt67, sbs2, ORDER, 1
	LDR r6, =sbs2
	
	//r0: sbs2
	LDR r0, [r6]
	
	// 取反
	MVN r0,r0
	//LDR r7, =0xFFFF
	//EOR r0, r0, r7
	//存储
	STR r0, [r6]	
	matrosecxor_ sbz5, sbz13, sbt48, ORDER, 1
	matrosecxor_ sbz12, sbt48, sbt56, ORDER, 1
	matrosecxor_ sbt53, sbt66, sbs3, ORDER, 1
	
	// 这个地方应该是s3不是x3
	matrosecxor_ sbt64, sbs3, sbs1, ORDER, 1
	//LDR r6, =sbs1
	LDR r6, =sbs1
	LDR r0, [r6]
	//LDR r7, =0xFFFF
	//EOR r0, r0, r7
	MVN r0,r0
	STR r0, [r6]
	//这里有错
	matrosecxor_ sbt56, sbt62, sbs6, ORDER, 1
	LDR r6, =sbs6
	LDR r0, [r6]
	//LDR r7, =0xFFFF
	//EOR r0, r0, r7
	MVN r0,r0
	STR r0, [r6]
	matrosecxor_ sbt48, sbt60, sbs7, ORDER, 1
	LDR r6, =sbs7
	LDR r0, [r6]
	//LDR r7, =0xFFFF
	//EOR r0, r0, r7
	MVN r0,r0
	STR r0, [r6]
	
	
	//precompute结束后，把sbs 存到sbx里面
	//sbs0-7在online部分就用不到了
	duplicate sbs0, sbx0, ORDER
	duplicate sbs1, sbx1, ORDER
	duplicate sbs2, sbx2, ORDER
	duplicate sbs3, sbx3, ORDER
	duplicate sbs4, sbx4, ORDER
	duplicate sbs5, sbx5, ORDER
	duplicate sbs6, sbx6, ORDER
	duplicate sbs7, sbx7, ORDER
	POP {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
	bx lr
	
	
sboxonline:


	PUSH {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}

	matrosecxor_ online_sbx3,  online_sbx5,  online_sby14, ORDER, 0
	matrosecxor_ online_sbx0,  online_sbx6,  online_sby13, ORDER, 0
	matrosecxor_ online_sby13, online_sby14, online_sby12, ORDER, 0
	matrosecxor_ online_sbx0,  online_sbx3,  online_sby9, ORDER, 0
	matrosecxor_ online_sbx0,  online_sbx5,  online_sby8, ORDER, 0
	matrosecxor_ online_sbx1,  online_sbx2,  online_sbt0, ORDER, 0
	matrosecxor_ online_sbt0,  online_sbx7,  online_sby1, ORDER, 0
	matrosecxor_ online_sby1,  online_sbx3,  online_sby4, ORDER, 0
	matrosecxor_ online_sby1,  online_sbx0,  online_sby2, ORDER, 0
	matrosecxor_ online_sby1,  online_sbx6,  online_sby5, ORDER, 0
	matrosecxor_ online_sbx4,  online_sby12, online_sbt1, ORDER, 0
	matrosecxor_ online_sby5,  online_sby8,  online_sby3, ORDER, 0
	matrosecxor_ online_sbt1,  online_sbx5,  online_sby15, ORDER, 0
	matrosecxor_ online_sbt1,  online_sbx1,  online_sby20, ORDER, 0
	matrosecxor_ online_sby15, online_sbx7,  online_sby6, ORDER,  0
	matrosecxor_ online_sby15,  online_sbt0,  online_sby10, ORDER, 0
	matrosecxor_ online_sby20, online_sby9,  online_sby11, ORDER, 0
	matrosecxor_ online_sbx7,  online_sby11, online_sby7, ORDER,  0
	matrosecxor_ online_sby10, online_sby11, online_sby17, ORDER, 0
	matrosecxor_ online_sby10, online_sby8,  online_sby19, ORDER, 0
	matrosecxor_ online_sbt0,  online_sby11, online_sby16, ORDER, 0
	matrosecxor_ online_sby13, online_sby16, online_sby21, ORDER, 0
	matrosecxor_ online_sbx0,  online_sby16, online_sby18, ORDER, 0
///////////////////////////////////////////////////////////////////////////////
	
//															tx         ty          tr tx ty tr的长度为order ，前面的长度为1
	matrosecandnew_ online_sby12, online_sby15, sby12,sby15,online_sbt2, sband1tr, ORDER + 1, 0,r12,ORDER
	
	//到这里没有问题
	matrosecandnew_ online_sby3, online_sby6, sby3, sby6, online_sbt3, sband2tr, ORDER+1, 0,r12,ORDER
	matrosecandnew_ online_sby4, online_sbx7, sby4, sbx7_for_online, online_sbt5, sband3tr, ORDER+1, 0,r12,ORDER
	matrosecandnew_ online_sby13, online_sby16, sby13, sby16, online_sbt7, sband4tr, ORDER+1, 0,r12,ORDER
	matrosecandnew_ online_sby5, online_sby1, sby5, sby1, online_sbt8, sband5tr, ORDER+1, 0,r12,ORDER
	matrosecandnew_ online_sby2, online_sby7, sby2,sby7, online_sbt10, sband6tr, ORDER+1, 0,r12,ORDER
	matrosecandnew_ online_sby9, online_sby11, sby9, sby11, online_sbt12, sband7tr, ORDER+1, 0,r12,ORDER
	matrosecandnew_ online_sby14, online_sby17, sby14, sby17, online_sbt13, sband8tr, ORDER+1, 0,r12,ORDER
	matrosecxor_ online_sbt3, online_sbt2, online_sbt4, ORDER, 0
	matrosecxor_ online_sbt5, online_sbt2, online_sbt6, ORDER, 0
	matrosecxor_ online_sbt8, online_sbt7, online_sbt9, ORDER, 0
	matrosecxor_ online_sbt10, online_sbt7, online_sbt11, ORDER, 0
	matrosecxor_ online_sbt13, online_sbt12, online_sbt14, ORDER, 0
	matrosecxor_ online_sbt4, online_sbt14, online_sbt17, ORDER, 0
	matrosecxor_ online_sbt9, online_sbt14, online_sbt19, ORDER, 0
	// 这里有错
	matrosecxor_ online_sbt17, online_sby20, online_sbt21, ORDER, 0
	matrosecxor_ online_sbt19, online_sby21, online_sbt23, ORDER, 0
	matrosecandnew_ online_sby8, online_sby10, sby8, sby10, online_sbt15, sband9tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt21, online_sbt23, sbt21, sbt23, online_sbt26, sband10tr, ORDER+1, 0,r12, ORDER
	matrosecxor_ online_sbt15, online_sbt12, online_sbt16, ORDER, 0
	matrosecxor_ online_sbt6, online_sbt16, online_sbt18, ORDER,  0
	matrosecxor_ online_sbt11, online_sbt16, online_sbt20, ORDER, 0
	matrosecxor_ online_sbt20, online_sby18, online_sbt24, ORDER, 0
	matrosecxor_ online_sbt23, online_sbt24, online_sbt30, ORDER, 0
	matrosecxor_ online_sbt18, online_sby19, online_sbt22, ORDER, 0
	matrosecxor_ online_sbt21, online_sbt22, online_sbt25, ORDER, 0
	matrosecxor_ online_sbt24, online_sbt26, online_sbt27, ORDER, 0
	matrosecxor_ online_sbt22, online_sbt26, online_sbt31, ORDER, 0
	matrosecandnew_ online_sbt25, online_sbt27, sbt25, sbt27, online_sbt28, sband11tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt31, online_sbt30, sbt31, sbt30, online_sbt32, sband12tr, ORDER+1, 0,r12, ORDER
	matrosecxor_ online_sbt28, online_sbt22, online_sbt29, ORDER, 0
	
	// https://eprint.iacr.org/2016/264.pdf 这里写错了
	matrosecxor_ online_sbt32, online_sbt24, online_sbt33, ORDER, 0
	matrosecxor_ online_sbt23, online_sbt33, online_sbt34, ORDER, 0
	matrosecxor_ online_sbt27, online_sbt33, online_sbt35, ORDER, 0
	matrosecxor_ online_sbt29, online_sbt33, online_sbt42, ORDER, 0
	matrosecandnew_ online_sbt29, online_sby2, sbt29, sby2, online_sbz14, sband13tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt24, online_sbt35, sbt24, sbt35, online_sbt36, sband14tr, ORDER+1, 0,r12, ORDER
	matrosecxor_ online_sbt36, online_sbt34, online_sbt37, ORDER, 0
	matrosecxor_ online_sbt27, online_sbt36, online_sbt38, ORDER, 0
	matrosecandnew_ online_sbt29, online_sbt38, sbt29, sbt38, online_sbt39, sband15tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt29, online_sby7, sbt29,sby7,online_sbz5, sband16tr, ORDER+1, 0,r12, ORDER
	matrosecxor_ online_sbt33, online_sbt37, online_sbt44, ORDER, 0
	matrosecxor_ online_sbt25, online_sbt39, online_sbt40, ORDER, 0
	matrosecxor_ online_sbt40, online_sbt37, online_sbt41, ORDER, 0
	matrosecxor_ online_sbt29, online_sbt40, online_sbt43, ORDER, 0
	matrosecxor_ online_sbt42, online_sbt41, online_sbt45, ORDER, 0
	matrosecandnew_ online_sbt44, online_sby15, sbt44, sby15, online_sbz0, sband17tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt37, online_sby6, sbt37, sby6, online_sbz1, sband18tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt33, online_sbx7, sbt33, sbx7_for_online, online_sbz2, sband19tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt43, online_sby16, sbt43, sby16, online_sbz3,  sband20tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt40, online_sby1, sbt40, sby1, online_sbz4,  sband21tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt42, online_sby11, sbt42, sby11, online_sbz6,  sband22tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt45, online_sby17, sbt45, sby17, online_sbz7,  sband23tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt41, online_sby10, sbt41, sby10, online_sbz8,  sband24tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt44, online_sby12, sbt44, sby12, online_sbz9,  sband25tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt37, online_sby3, sbt37, sby3, online_sbz10,  sband26tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt33, online_sby4, sbt33, sby4, online_sbz11,  sband27tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt43, online_sby13, sbt43, sby13, online_sbz12,  sband28tr, ORDER+1, 0,r12, ORDER
	matrosecandnew_ online_sbt40, online_sby5, sbt40, sby5, online_sbz13,  sband29tr, ORDER+1,0,r12, ORDER
	matrosecandnew_ online_sbt42, online_sby9, sbt42, sby9, online_sbz15,  sband30tr, ORDER+1,0,r12, ORDER
	matrosecandnew_ online_sbt45, online_sby14, sbt45, sby14, online_sbz16,  sband31tr, ORDER+1,0,r12, ORDER
	matrosecandnew_ online_sbt41, online_sby8, sbt41, sby8, online_sbz17,  sband32tr, ORDER+1,0,r12, ORDER
//////////////////////////////////////////////////////////////////////////////////////////////
	matrosecxor_ online_sbz15, online_sbz16, online_sbt46, ORDER, 0
	matrosecxor_ online_sbz16, online_sbz17, online_sbt55, ORDER, 0
	matrosecxor_ online_sbz7, online_sbz8, online_sbt52, ORDER, 0
	matrosecxor_ online_sbz6, online_sbz7, online_sbt54, ORDER, 0
	matrosecxor_ online_sbz4, online_sbt46, online_sbt58, ORDER,0
	matrosecxor_ online_sbz3, online_sbt54, online_sbt59, ORDER,0
	matrosecxor_ online_sbz4, online_sbt59, online_sbt64, ORDER,0
	matrosecxor_ online_sbz10, online_sbz11, online_sbt47, ORDER, 0
	matrosecxor_ online_sbz9, online_sbz10, online_sbt49, ORDER, 0
	matrosecxor_ online_sbt49, online_sbt58, online_sbt63,ORDER, 0
	matrosecxor_ online_sbz1, online_sbt63, online_sbt66, ORDER, 0
	matrosecxor_ online_sbt52, online_sbt58, online_sbt62, ORDER, 0
	matrosecxor_ online_sbz0, online_sbz3, online_sbt53, ORDER, 0
	matrosecxor_ online_sbz2, online_sbz12, online_sbt50, ORDER, 0
	matrosecxor_ online_sbt50, online_sbt53, online_sbt57, ORDER, 0
	matrosecxor_ online_sbt46, online_sbt57, online_sbt60, ORDER, 0
	matrosecxor_ online_sbz14, online_sbt57, online_sbt61, ORDER, 0
	matrosecxor_ online_sbt61, online_sbt62, online_sbt65, ORDER, 0
	
	matrosecxor_ online_sbt59, online_sbt63, online_sbs0,ORDER, 0
	matrosecxor_ online_sbz2, online_sbz5, online_sbt51, ORDER, 0
	matrosecxor_ online_sbt51, online_sbt66, online_sbs4, ORDER, 0
	matrosecxor_ online_sbt47, online_sbt65, online_sbs5, ORDER, 0
	matrosecxor_ online_sbt64, online_sbt65, online_sbt67, ORDER, 0
	matrosecxor_ online_sbt55, online_sbt67, online_sbs2, ORDER, 0	
	matrosecxor_ online_sbz5, online_sbz13, online_sbt48, ORDER, 0
	matrosecxor_ online_sbz12, online_sbt48, online_sbt56, ORDER, 0
	matrosecxor_ online_sbt53, online_sbt66, online_sbs3, ORDER, 0
	//下面应该是s3，不是x3
	matrosecxor_ online_sbt64, online_sbs3, online_sbs1, ORDER, 0
	matrosecxor_ online_sbt56, online_sbt62, online_sbs6, ORDER, 0
	matrosecxor_ online_sbt48, online_sbt60, online_sbs7, ORDER, 0
	
	// 别忘了把s存回到x里面
	duplicate online_sbs0, online_sbx0, 1
	duplicate online_sbs1, online_sbx1, 1
	duplicate online_sbs2, online_sbx2, 1
	duplicate online_sbs3, online_sbx3, 1
	duplicate online_sbs4, online_sbx4, 1
	duplicate online_sbs5, online_sbx5, 1
	duplicate online_sbs6, online_sbx6, 1
	duplicate online_sbs7, online_sbx7, 1
	POP {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
	bx lr