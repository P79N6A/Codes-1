;*************************************************************
ds_segment segment
	NUM DW 76,69,84,90,73,88,99,63,100,80  
	S6 DW 0  
	S7 DW 0  
	S8 DW 0  
	S9 DW 0  
	S10 DW 0  
ds_segment ends
;*************************************************************
CODE SEGMENT
MAIN PROC FAR
;-------------------------------------------------------------
ASSUME CS:CODE, DS:DSEG

START:  
	PUSH DS  
	SUB AX, AX  
	PUSH AX  
	MOV AX, ds_segment 
	MOV DS, AX  
	CALL SUB1  
	RET  
MAIN ENDP
;-------------------------------------------------------------
SUB1 PROC NEAR  
	PUSH AX  
	PUSH BX 
	PUSH CX  
	PUSH SI  
	MOV SI, 0  
	MOV CX, 10 ; 循环十次
NEXT:  
	MOV AX, NUM[SI]  
	MOV BX, 10
	DIV BL
	MOV BL, AL
	CBW  ; convert byte to word :扩展al 
	SUB BX, 6  
	SAL BX, 1	; 左移一位，X2
	INC S6[BX]  ; 增加个数，S6是后继单元的首地址
	ADD SI,2  
LOOP NEXT  
	POP SI  
	POP CX  
	POP BX  
	POP AX  
	RET  
SUB1 ENDP

CODE ENDS
;-------------------------------------------------------------  
END START