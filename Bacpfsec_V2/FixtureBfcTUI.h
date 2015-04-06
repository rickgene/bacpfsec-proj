/**
 * @file   FixtureBfcTUI.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  CppUnit Fixture setup for BfcTUI class
 *
 * FixtureBfcTUI is used in TestBfcTUI for BfcTUI Class
 */

#ifndef _FIXTUREBFCTUI_H_
#define _FIXTUREBFCTUI_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "BfcTUI.h"
#include "Task.h"
#include <vector>
#include <iostream>

class FixtureBfcTUI : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(FixtureBfcTUI);
  CPPUNIT_TEST(testPrintDay);
  CPPUNIT_TEST(testShowRecord);
  CPPUNIT_TEST(testWriteRecord);
  CPPUNIT_TEST_SUITE_END();

 private:
  BfcTUI* tui;

 public:
  void setUp() {
    tui = new BfcTUI();
  }

  void tearDown() {
    delete tui;
  }

  /**    Tests for BfcTUI::printDay(ostream&, Date, int);
   *      
   */ 
  void testPrintDay() {
    std::stringstream ss;
    tui->printDay(ss,Date(20150302),10);
    std::string s;
    ss>>s;
    CPPUNIT_ASSERT("2015-3-2" == s);
  }

  /**    Tests for BfcTUI::showRecord(std::ostream&,std::vector<Task>&,int);
   *      
   */ 
  void testShowRecord() {
    std::vector<Task> ts;
    ts.push_back(Task("Test",std::vector<State>(),1));
    ts[0].getStates().push_back(State("S1",Date(20150301)));
    std::stringstream ss;
    tui->showRecord(ss,ts,1);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Taskname:TestDetails:[S1]2015-3-1" == result);
  }

  /**    Tests for BfcTUI::writeRecord(std::ostream&,std::vector<Task>&);
   *      
   */ 
  void testWriteRecord() {
    std::vector<Task> ts;
    ts.push_back(Task("Test",std::vector<State>(),1));
    ts[0].getStates().push_back(State("S1 + S2 + S3",Date(20150301)));
    std::stringstream ss;
    tui->showRecord(ss,ts,1);
    std::string s, result="";
    while (ss>>s) {
      result += s;
    }
    CPPUNIT_ASSERT("Taskname:TestDetails:[S1+S2+S3]2015-3-1" == result);
  }
};
#endif
