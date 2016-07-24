; 初始：ax: 存放除数低位		dx: 存放除数高位     cx: 除数
; 返回：ax: 结果的低16位        dx: 结果的高16位     cx: 余数
divdw:
	jcxz ed 		  ; 除数为0的情况特别考虑下
	push bx			  ; 保存bx的值
	
	push ax           ; 保存低位
	mov ax, dx
	mov dx, 0
	div cx            ; 高位余数在dx中
	mov bx, ax        ; 将高位商存放与bx中
	pop ax            ; 拿出低位
	div cx
	mov cx, dx        ; cx保存余数
	mov dx, bx        ; 高位商给dx
	
	pop bx            ; 恢复bx
ed:
	ret