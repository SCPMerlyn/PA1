README File
Name: Simple URL Parser
Description: The project allows for a user to input a URL and the program will take care of analyzing if it is a valid URL and printing its components. If it is not a valid URL, the program will let the user know which component(s) made it invalid.
Resource: (https://developer.mozilla.org/enUS/docs/Learn/Common_questions/What_is_a_URL)
Example:
1) The user is asked to input a URL
2) Once the user inputs the URL and presses Enter the program checks the components of the URL and displays them.
3) If any or all parts of the URL are invalid the program will display the invalid parts to help the user fix it

For the URL to be considered valid it must be in one of the valid formats and each component must meet the requirements. 
(* denotes optional components)

Valid Formats:        protocol://<x>.<y>.<z>:port/path?variable=variable
  
                                ex) https://cs.utdallas.edu:80/directory/faculty/people.html?name=Robert
                                protocol://<x>.<y>.<z>/path?variable=variable
                                
                                ex) https://cs.utdallas.edu/directory/faculty/people.html?name=Robert
                                protocol://<x>.<y>.<z>:port/path
                                
                                ex) https://cs.utdallas.edu:80/directory/faculty/people.html
                                protocol://<x>.<y>.<z>/path
                                
                                ex) https://cs.utdallas.edu/directory/faculty/people.html
Protocol:      http, https, ftp, ftps

Domain:       z value can be com, net, edu, biz, gov

Port*:	 a number between 1 to 65535(inclusive)

File Path:      must start with '/' and end with either .html or .htm

Parameters*:   must start with’?’ and have a ‘=’ between the 2 variables, they can be different

Installation: To use it you can either use an IDE that supports C++ or run it in your terminal. 
Install in terminal

    1) To install the necessary C/C++ development libraries type in                                            “sudo apt-get install build-essential”. Since you are using sudo it will ask you for you for your account password
    
    3) To verify it was downloaded you can type in gcc -version
   
    5) Now you can either
        a. open a C++ file using a file editor and name the file using the convention filename.cpp to copy and paste the code, save and exit.
        
        b. download the .cpp file and make sure to compile and run from which ever folder you save it into.
        
    4) To compile and execute it you can either use
    
        a. (compile)sudo g++ filename.cpp then (execute)./a.out
        
        b. (compile)sudo g++ -o filename filename.cpp then (execute)./filename 
