.MODEL SMALL
.STACK 64
.DATA

.CODE
portInitialize PROC
	;Set Divisor Latch Access Bit
	mov dx,3fbh 			; Line Control Register
	mov al,10000000b		;Set Divisor Latch Access Bit
	out dx,al
	
	;Set LSB byte of the Baud Rate Divisor Latch register.
	mov dx,3f8h			
	mov al,0ch			
	out dx,al

	;Set MSB byte of the Baud Rate Divisor Latch register.
	mov dx,3f9h
	mov al,00h
	out dx,al

	;Set port configuration
	mov dx,3fbh
	mov al,00011011b
	out dx,al
	
	
	RET
portInitialize ENDP


MAIN PROC FAR
	CALL portInitialize
	
	INFINITYLOOP:
	;Check that Data Ready
	mov dx , 3FDH		; Line Status Register
	CHK:
	in al , dx 
	AND al , 1
  	JZ CHK
	;If Ready read the VALUE in Receive data register
	mov dx , 03F8H
  	in al , dx 
	;display the char
	MOV AH,0EH
	INT 10H
	JMP INFINITYLOOP

	
MAIN ENDP
END MAIN