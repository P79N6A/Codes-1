;*************************************************************
ds_segment segment
	count equ 20
	array dw 20 dup(?)
	count_p db 0	; positive
	arrayp dw 20 dup(?)
	count_n db 0	; negative
	arrayn dw 20 dup(?)
	string1 db 0dh, 0ah, 'The number of positive number is:$'
	string2 db 0dh, 0ah, 'The number of negative number is:$'
	crlf db 0dh, 0ah, '$' 	; 换行回车
ds_segment ends
;*************************************************************
ss_segment segment
	
ss_segment ends
;*************************************************************
code segment
main proc far
;-------------------------------------------------------------
assume cs:code, ds:ds_segment, ss:ss_segment

start:
	push ds
	mov ax, 0
	push ax
	mov ax, ds_segment
	mov ds, ax
	
begin:
	mov cx, count
	lea bx, array
	lea si, arrayp
	lea di, arrayn
	
begin1:
	mov ax, [bx]
	cmp ax, 0		;结果为负数则转移
	js negative
	mov [si], ax
	inc count_p
	add si, 2
	jmp short next
negative:
	mov [di], ax
	inc count_n
	add di, 2
next:
	add bx, 2
loop begin1

	lea dx, string1
	mov al, count_p
	call display
	lea dx, string2
	mov al, count_n
	call display
	ret
main endp
;-------------------------------------------------------------
display proc near
	mov ah, 9
	int 21h
	aam           ; AH←AL/10(商)，AL←AL%10(余数)
	add ah, '0'
	mov dl, ah
	mov ah, 2
	int 21h
	add al, '0'
	mov dl, al
	mov ah, 2
	int 21h
	lea dx, crlf
	mov ah, 9
	int 21h
	ret
display endp
code ends
;-------------------------------------------------------------
end start