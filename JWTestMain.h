////////////////////* INFO */////////////////////////
// Writer: Jinwoo Park
// E-Mail: jin.woo.park@ericsson.com
// Purpose: TDD Seminar Example
////////////////////////////////////////////////////

////////////////////* Aim */////////////////////////
// 1. Test provides as much information as possible
// 2. Each test case is dependent from others
// 3. Test suite can run repeatedly
// 4. Fast and Simple
////////////////////////////////////////////////////

/////////////////* How To Use *////////////////////
/*
#include "JWTestMain.h"

//Test Suite Starts Here
START_TEST_SUITE(SUITE_NAME)

	//Test Case1 Starts Here
	START_TEST_CASE("Test Case1")
		EXPECT_TRUE(1==1);
		EXPECT_FALSE(2==1);
		TEST_INFO("So Simple Test!");
	END_TEST_CASE()
	
	//Test Case2 Starts Here
	START_TEST_CASE("Test Case2")
		EXPECT_EQUAL(3, 3);
		EXPECT_STR_EQUAL("haha", "haha");
	END_TEST_CASE()
	
END_TEST_SUITE()

int main(void)
{
	RUN_TEST_SUITE(SUITE_NAME);
	return 0;
}
*/
///////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>

#include "JWTestUtil.h"

using std::string;
using std::cout;
using std::endl;

class JWTestMain
{
protected:
	//Constructor & Destructor
	JWTestMain()
	: successNum(0), failNum(0), failFlag(false)
	{}
	virtual ~JWTestMain() {};

	//Test Functions
	void init()
	{
		successNum=0;
		failNum=0;
		failFlag=false;
	}
	void testInfo(const string str, const char* fileName, const int line) const
	{
		JWTestUtil::SETCOLOR(yellow);
		cout<<"TEST_INFO) "<<str<<endl;
		JWTestUtil::SETCOLOR(white);
	}
	void testFail(const string str, const char* fileName, const int line)
	{
		JWTestUtil::SETCOLOR(red);
		cout<<"TEST_FAIL) "<<str<<endl;
		cout<<"<File: "<<fileName<<", Line "<<line<<">"<<endl;
		JWTestUtil::SETCOLOR(white);
		failFlag=true;
	}
	void checkResult(const bool result, const char* exp, const char* description, const char* fileName=__FILE__, const int line =__LINE__)
	{
		if(!result)
		{
			JWTestUtil::SETCOLOR(red);
			cout<<endl<<"Error!!"<<endl;
			JWTestUtil::SETCOLOR(white);
			cout<<"REASON: \""<<exp<<"\" is "<<description<<endl;
			cout<<"<File: "<<fileName<<", Line "<<line<<">"<<endl;
			failFlag=true;
		}
	}
	void printTestCaseResult()
	{
		switch(failFlag){
			case true:
				JWTestUtil::SETCOLOR(red);
				cout<<"Test Case Failed!"<<endl;
				JWTestUtil::SETCOLOR(white);
				failNum++;
				break;
			case false:
				cout<<"Test Completed Successfully!"<<endl;
				successNum++;
				break;
		}
		cout<<endl;
		failFlag=false;
	}
	void printSuiteResult()
	{
		cout<<"* Success Number: "<<successNum<<endl;
		cout<<"* Fail Number: "<<failNum<<endl;
	}
	virtual void testSuite() = 0;
	
public:
	void testRun()
	{
		testSuite();
	}
	
private:
	int successNum;
	int failNum;
	bool failFlag;
};

#define RUN_TEST_SUITE(SUITE_NAME)\
		{\
			SUITE_NAME ts;\
			ts.testRun();\
		}

#include "JWMacroClass.h"
#include "JWTestAssertions.h"