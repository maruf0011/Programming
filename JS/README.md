#Chapter One
	* values : junk of data 
	* types of values : number string boolean object function undefined
	* Numbers 
		* 64 bit 
		* n = 10.3434
	* arithmetic 	
	* special number : Nan ,Infinity
	* Strings : single and double quote both works as a general case of c++
	* Unary operators
	* Boolean values
	* comparision as general 
		* (Nan==Nan ) not owrks
		* (Nan == something) not works
	* Logical Operators
		* and or not
	* conditional operator
	* Undefined values
	* autometic type converstion 
		* works as general case of the code
		* precedence works as general case
		* to remove type conversion use === or !== for comparision
	* shor-circuit of logical operator 
		* true||x , false && x
	*



# chapter 2
	* varibale
		* declare usign var name;
	* environment
	* console.log()
	* return value
	* prompt and confirm
		* confirm()
		* prompt()
	* loop 
		* while 

# chapter 3
	* function :
		* dec : var name = function(parameter ...){ return ...}
		* var name .... insde a function is always local
		* you can access a varible of outside of the function as long as you do not make a variable of your own in function 
			of your own in same name in function
		* nested scoping
		* lexical scoping
		* function is like a variable 
			you can assing anything in var anytime 
		* define function
			* var name = function(var.. ){} and function name(var ..){ } both are same
		* you can define  a fucntion in anyplace of the file 
			* its not necessary to define a function before using it
		* never define a function in if clause 
		* closure return function from a function to access local varibale

# Chapter 4 ARRAY
	* array , var ar = [......];
	* object 
		* var name = {
						property : value,
						..............
						.............

						property : value
					}
		* if property name is not valid the use double quote .
		* any property of the object can be set latter name.property = 'asdfasdf';
		* delete operator delete a property from an object 
	* arguments object 
	* map object 
	* math object 
	* function :
		* function name.apply(,,,,,,,) it passes an array of arguments for calling a function 
		