;*************************************************************
ds_segment segment
	val1 db ?
	val2 db ?
ds_segment ends
;*************************************************************
ss_segment segment
	
ss_segment ends
;*************************************************************
code segment
;-------------------------------------------------------------
assume cs:code, ds:ds_segment, ss:ss_segment

main:
	mov ax, ds_segment
	mov ds, ax
	mov ax, ss_segment
	mov ss, ax
	
	mov al, val1
	mov bl, val2
	xor ax, bx
	; 测试第一位是不是1，如果是同奇偶，则为0，否则为1
	test ax, 0001h
	jz subPro
	test bl, 0001h
	jz exit
	; B是奇数，A、B交换
	xchg bl, val1
	mov val2, bl
	jmp exit
subPro:
	test bl, 0001h
	jz exit
	inc val1
	inc val2
exit: 
	mov ah, 4ch
	int 21h
code ends
;*************************************************************
end main
	
	
	