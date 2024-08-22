# COMP 411 FALL 2020 LAB 4 STARTER CODE

.data 0x0
  executionTime:	.word 0
  numberOfProcessors:	.word 0 
  totalPrice:		.word 0
  currentCPI:		.word 0
  currentPrice:		.word 0
  ratioInstrClock:	.word 0

  
  timePrompt:		.asciiz "Please enter the desired execution time (in seconds): "	
  pricePrompt:		.asciiz "Please enter the price of the processor(in dollars): "
  cpiPrompt:		.asciiz "Please enter the average CPI of the processor: "
  executionTimeIs:	.asciiz "Execution time in seconds: "
  isDesired:		.asciiz "This processor meets the desired execution time, adding to cart."
  notDesired:		.asciiz "This processor does not meet the desired execution time."
  totalProcessors:	.asciiz "Total number of processors purchased: "
  isTotalPrice:		.asciiz "Total price of processors purchased: "
  doneShopping:		.asciiz "You are done shopping for processors."
  newline:		.asciiz "\n"

.text
main:
#Print the prompt for time
  addi 	$v0, $zero, 4  			# system call 4 is for printing a string
  la 	$a0, timePrompt 		# address of timePrompt is in $a0
  syscall           			# print the string 
#Read the Execution TIme
  addi	$v0, $0, 5			# system call 5 is for reading an integer
  syscall 				# integer value read is in $v0
  add	$8, $0, $v0			# copy the execution time into $8
  sw 	$s0, numberOfProcessors		# number of Processors stored in $s0
  sw 	$s1, totalPrice			# total Price stored in $s1	
  sw 	$s2, currentCPI			# current CPI stored in $s2
  sw 	$s3, currentPrice		# current price stored in $s3
  sw 	$s4, ratioInstrClock		# ratio of Intuctions/Clock Rate stored in $s4
  j loop
 
 								
loop:
#Print pricePrompt
 	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, pricePrompt	 		# address of totalProcessors prompt
  	syscall           			# print the string
#Read pricePrompt
  	addi	$v0, $0, 5			# system call 5 is for reading an integer
  	syscall 				# integer value read is in $v0
  	add	$s3, $0, $v0			# copy the price into currentPrice
#Determine if Price == 0
	beq $s3, $0, exit
#Print cpiPrompt
 	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, cpiPrompt	 		# address of totalProcessors prompt
  	syscall           			# print the string
#Read cpiPrompt
  	addi	$v0, $0, 5			# system call 5 is for reading an integer
  	syscall 				# integer value read is in $v0
  	add	$s3, $0, $v0			# copy the execution time into $8
#Print cpiPrompt
 	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, isDesired	 		# address of isDesired prompt
  	syscall           			# print the string
#Newline
   	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, newline 			# address of newline prompt
  	syscall           			# print the string
#Determine if execution time <= desired time
#	ble ,, incriment

incriment:
#Add to number of processors
	addi $s0, $s0, 1 
#Add to price
	add $s1, $s1, $s3
#set current execution to zero
	sub $s5, $s5, $s5
#set current price to zero
	sub $s3, $s3, $s3
#set current CPI to zero
	sub $s2, $s2, $s2
#Jump back into loop
	j loop


exit:
#Print done shopping
 	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, doneShopping	 		# address of isTotalPrice prompt
  	syscall           			# print the string
#Newline
   	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, newline 			# address of newline
  	syscall           			# print the string 
#Print total processors purchased
 	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, totalProcessors 		# address of totalProcessors prompt
  	syscall           			# print the string
  	li $v0, 1        			# system call code 4 print_int
        move $a0, $s0      			# integer to print
        syscall          			# print it
#Newline
   	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, newline 			# address of newline
  	syscall           			# print the string 	
#Print total price
 	addi $v0, $0, 4  			# system call 4 is for printing a string
	la $a0, isTotalPrice	 		# address of isTotalPrice prompt
  	syscall           			# print the string
  	li $v0, 1        			# system call code 4 print_int
        move $a0, $s1      			# integer to print
        syscall          			# print it
#================================================================================================#
# Boilerplate system call to terminate program.
 ori $v0, $0, 10       
 syscall   
