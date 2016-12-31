;*****************************************************************
ds_segment segment
	endWord db 'The program is complated. Press any key to exit...$'
ds_segment ends
;*****************************************************************
es_segment segment

es_segment ends
;*****************************************************************
ss_segment segment

ss_segment ends
;*****************************************************************
code segment
;-----------------------------------------------------------------
assume cs:code, ds:ds_segment, es:es_segment, ss:ss_segment

main:
; set DS ES SS register to current data segment
	mov ax, ds_segment
	mov ds, ax
	mov ax, es_segment
	mov es, ax
	mov ax, ss_segment
	mov ss, ax
; begin to move the data
	push ds
	mov ax, 0ffffh
	mov ds, ax
	mov ax, 0000h
	mov es, ax
	mov si, 0000h
	mov di, 0200h
	mov cx, 14	; 0 ~ d
moveData:
	mov al, ds:[si]
	mov es:[di], al
	inc si
	inc di
loop moveData
	pop ds
	lea dx, endWord
	mov ah, 9
	int 21h
	mov ah, 1
	int 21h
	mov ah, 4ch
	int 21h
code ends
;*****************************************************************
end main
	
	