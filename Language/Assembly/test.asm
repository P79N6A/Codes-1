Code Segment
Assume CS:Code,DS:Code
; －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
; 功能：显示指定地址（Str_Addr）的字符串
; 入口：
; Str_Addr＝字符串地址（要求在数据段）
; 用法: Output Str_Addr
; 用法举例：Output PromptStr
Output MACRO Str_Addr
	lea dx,Str_Addr
	mov ah,9
	int 21h
EndM
; －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
Number dw ?
Press_Key db 'The complated. Press any key to exit...$' 
Please_Input db 'Please enter 4 numbers : $' 
Start: push cs
	pop ds
	push cs
	pop es ;使数据段、附加段与代码段同段
	
	Output Please_Input
	mov cx, 5 ; 考虑回车符，多循环一次来读取
	mov ah, 1
	mov dx, 0 ; dx清零，用于四位字符输入进栈
Input_Number:
	int 21h
	mov dl,al
	push dx
loop Input_Number
	
; 将四位字符转换为四位数
	pop dx ; 清除回车符
	mov dx, 0
	mov bx, 1
	mov Number, 0
	mov cx, 4
Get_Number:
	mov ax, 0
	pop ax;
	sub ax, '0'
	mul bx
	add Number, ax
	; bx 的值乘10
	mov ax, bx
	mov bx, 10
	mul bx
	mov bx, ax
loop Get_Number
	
	mov ax, Number
	mov cx,16
Disp_Binarry: 
	mov dl,'1'
	shl ax,1
	push ax
	mov ah,2
	jc $+4
	mov dl,'0'
	int 21h
	pop ax
loop Disp_Binarry
; －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
Exit_Proc: Output Press_Key ;提示操作完成，按任意键结束程序
	mov ah,1
	int 21h
	mov ah,4ch ;结束程序
	int 21h
Code ENDS
END Start ;编译到此结束