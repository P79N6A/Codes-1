;*************************************************************
dataseg segment
	message db 'Please input ten numbers:', 0dh, 0ah, '$'
	message2 db 0dh, 0ah, 'The result is: $'
	buffer db 10 dup(?)
	password db 7,5,9,1,3,6,8,0,2,4
dataseg ends
;*************************************************************
codeseg segment
assume cs:codeseg, ds:dataseg
;-------------------------------------------------------------
start:
	mov ax, dataseg
	mov ds, ax
	lea dx, message
	mov ah, 09h
	int 21h
	
	lea bx, password
	lea si, buffer
	mov cx, 10
	
input:
	mov ah, 01
	int 21h
	sub al, 30h
	xlat
	add al, 30h
	mov [si], al
	inc si
	loop input
	
	lea dx, message2
	mov ah, 09h
	int 21h
	
	lea si, buffer
	mov cx, 10
	mov ah, 02h
output:
	mov dl, [si]
	int 21h
	inc si
	loop output
	
	mov ah, 4ch
	int 21h
codeseg ends
;*************************************************************
end start