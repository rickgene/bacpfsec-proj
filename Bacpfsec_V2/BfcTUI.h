/**
 * @file   BfcTUI.h
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Header file of BfcTUI inherited from BfcPrototype
 *
 * BfcTUI Class is used to build the text-based user interface
 */
#ifndef _BFCTUI_H_
#define _BFCTUI_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Date.h"
#include "Task.h"
#include "BfcPrototype.h"
#include <vector>

/**
 * @brief  BfcTUI Class is inherited from BfcPrototype
 * 
 * BfcTUI provides some interesting functions to build the text-based UI
 * This is one main variant of the Bacpfsec Project main
 *
 */
class BfcTUI : public BfcPrototype {
 public:
  /**    Default constructor
   *     
   */ 
  BfcTUI();
  
  /**    Destructor
   *
   */ 
  ~BfcTUI();

  /**    Print given date with given width
   *     @param os        ostream
   *     @param d         a Date object
   *     @param witth     desired output width
   *
   */
  void printDay(std::ostream& os, Date d, int width);

  /**    showRecord to ostream
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *     @param s         status integer
   *
   */
  void showRecord(std::ostream& os, std::vector<Task>& ts, int s);

  /**    writeRecord to ostream
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *
   */
  void writeRecord(std::ostream& os, std::vector<Task>& ts);

  /**    briefReport to ostream
   *     @param os        ostream
   *     @param ts        reference to a task vector
   *
   */
  void briefReport(std::ostream& os, std::vector<Task>& ts);

 private:
};
#endif
