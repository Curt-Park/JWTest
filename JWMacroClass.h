#pragma once

/* Test Macro Class */
#define START_TEST_SUITE(SUITE_NAME)\
	class SUITE_NAME : public JWTestMain {\
	friend void testSetup();\
	public:\
		SUITE_NAME() : suiteName(#SUITE_NAME) {}\
	private:\
		void testSuite(){\
			init();\
			cout<<endl;\
			JWTestUtil::SETCOLOR(green);\
			cout<<"[RUN	] "<<suiteName<<" starts!"<<endl;\
			JWTestUtil::SETCOLOR(white);
		
#define END_TEST_SUITE()\
			JWTestUtil::SETCOLOR(green);\
			cout<<"[END	] "<<suiteName<<" end!"<<endl<<endl;\
			cout<<"[RESULT	]"<<endl;\
			JWTestUtil::SETCOLOR(white);\
			printSuiteResult();\
		}\
	private:\
	string suiteName;\
	};
	
#define START_TEST_CASE(TEST_NAME)\
		{\
			cout<<endl<<"======TEST CASE STARTS======"<<endl;\
			JWTestUtil::SETCOLOR(dark_white);\
			cout<<"Test Name: <"<<TEST_NAME<<">"<<endl;\
			JWTestUtil::SETCOLOR(white);
#define END_TEST_CASE()\
			cout<<"========TEST CASE END======="<<endl;\
			printTestCaseResult();\
		}
