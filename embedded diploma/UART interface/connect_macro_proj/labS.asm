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
	;get char from user
	MOV AH,0
	INT 16H
	PUSH AX
	;Check that Transmitter Holding Register is Empty
	mov dx , 3FDH		; Line Status Register
	AGAIN:  
	in al , dx 
	AND al , 00100000b
  	JZ AGAIN
	POP AX
	;If empty put the VALUE in Transmit data register
	mov dx , 3F8H		; Transmit data register
  	out dx , al 

	;display the char
	MOV AH,0EH
	INT 10H
	JMP INFINITYLOOP

	
MAIN ENDP
END MAIN