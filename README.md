# How to use
```C++
 #include <iostream>
 #include "JWTestMain.h"
 
 //Test Suite Starts Here
 START_TEST_SUITE(SUITE_NAME)
     //Test Case1 Starts Here
     START_TEST_CASE("Test Case1")
         EXPECT_TRUE(1==1); // Ends with semicolon!
         EXPECT_FALSE(2==1);
         TEST_INFO("So Simple Test!");
     END_TEST_CASE()
     
     //Test Case2 Starts Here
     START_TEST_CASE("Test Case2")
         EXPECT_EQUAL(3, 3); 
         EXPECT_STR_EQUAL("haha", "haha");
     END_TEST_CASE()
 
     //Test Case3 Starts Here
     START_TEST_CASE("Test Case3")
         char c;
         std::cout<<"Don's input any number"<<std::endl;
         std::cin>>c;
         if(c>='0' && c<='9')
         {   
             TEST_FAIL("Just Fail!!!");
         }   
     END_TEST_CASE()
 END_TEST_SUITE()
 
 int main(void)
 {
     RUN_TEST_SUITE(SUITE_NAME);
     return 0;
 }
```

# Result
![alt text](https://github.com/Curt-Park/JWTest/blob/master/ex_result.png "Example Result")

# Functionalities
1. EXPECT_EQUAL(A,B): check A equals to B
2. EXPECT_STR_EQUAL(A,B): check str_A equals to str_B
3. EXPECT_TRUE(A): check A returns true
5. EXPECT_FALSE(B): check B returns false
6. TEST_INFO(A): add a comment in a test case
7. TEST_FAIL(A): trigger test failure


