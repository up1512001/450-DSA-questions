/*

immutable string can increase performance of system
-> two objects shares same address this design patterns called ' FLYWEIGHT ' means if possible then reuse object
----------------------------------------------------------------------------------------------
string str = "Utsav";
heap memory of string pool there will be stored utsav and gives address
string str1 = "Utsav"
this will not create other address both points to same location
and if str = "Patel"
then new object of string in heap memory will be created and address of that will be changed
so every time you assign new value to that string that will create new address and store that string value

so you can not change existing string value (this is call immutable)

and if you write String s1 = new String("Utsav") this will not use pool memory this will use heap memory and creates string object
->but "Utsav" comes from string pool means from pool it will take "Utsav" address to heap memory

----------------------------------------------------------------------------
By using string buffer and string builder we can able to make string mutable


*/
