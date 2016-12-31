;******************************************
ds_segment segment
ds_segment ends
;******************************************
ss_segment segment
ss_segment ends
;******************************************
code segment
;------------------------------------------
assume cs:code, ds:ds_segment, ss:ss_segment

main:
	mov ax, ds_segment
	mov ds, ax
	mov ax, ss_segment
	mov ss, ax
	mov ax, 7517h
	; 开始赋值
	mov dl, al
	and dl, 0fh
	mov cl, 4
	push ax
	rol ax, cl
	mov dh, ah
	and dh, 0fh
	pop ax
	mov cl, 8
	ror ax, cl
	mov bl, al
	and bl, 0fh
	mov cl, 4
	rol ax, cl
	mov bh, ah
	and bh, 0fh
	mov al, bh
	mov cl, dh
	mov ah, 4ch
	int 21h
code ends
;******************************************
end main
	
	
	