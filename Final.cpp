


#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;
int storeClock;
class Customer {
 public:
  int inTime;
  int outTime;
  int waitTime;
  int orderTime;
  int serviceTime;
  Customer *next;

  Customer()
      : inTime(storeClock),
        outTime(0),
        waitTime(0),
        next(NULL),
        serviceTime(0) {
    orderTime = rand() % 6 + 1;
  }
};
class Queue {
 public:
  Customer *head;

  Queue() : head(NULL) {}

  void enqueue() {
    Customer *temp = new Customer();

    if (head == NULL) {
      head = temp;

      cout << "added a new customer to line at time: " << temp->inTime
           << " and order: " << temp->orderTime
          << endl;

    } else {
      Customer *another = head;
     
      
      while (another->next != NULL) {
        another = another->next;
       
      }
      another->next = temp;
      
      
      

      temp->next = NULL;
      cout << "added a new customer to line at time: " << temp->inTime
           << " and order: " << temp->orderTime
           << endl;
    }
  }

  void dequeue() {
    Customer *remove;
    remove = head;
    head = head->next;
    cout << "customer leaves at: " << storeClock << " mins" << endl;
    delete remove;
    if(head!=NULL) {
      head->waitTime = storeClock - head->inTime;
      
      
      cout << " next customer waits in line for: " << head->waitTime << " mins" <<  endl;
    }
   
  }
};

int main() {
  srand(time(NULL));
  Queue myStore;
  double customerCount = 0.0;
  int queueLength = 0;
  int waitTimeSum = 0;
  int waitTimeSum2 = 0;
  int serviceTimeSume = 0;
  int minWaitTime = 99999;
  int maxWaitTime = -1;
  int minServiceTime = 99999;
  int maxServiceTime = -1;
  int randomNum;
  double queuelengthsum = 0;
  int minQueueTime = 99999;
  int maxQueueTime = -1;

  int time1;
  int time2;
  int time3;
  int time4;
  int time5;
  int time6;

  while (storeClock < 1020) {
    storeClock++;
    if (storeClock <= 120) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 30) {
       cout << "at time: " << storeClock << " we have 1 new customer" << endl;
        customerCount++;
        myStore.enqueue();
       
        

        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived "
             << endl;
      }
    }

    else if (storeClock > 120 && storeClock <= 210) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 10) {
        cout << "at time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        myStore.enqueue();
       
        
        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived" << endl;
      }
    }

    else if (storeClock > 210 && storeClock <= 330) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 40) {
       cout << "at time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        myStore.enqueue();

        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived" << endl;
      }
    }

    else if (storeClock > 330 && storeClock <= 570) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 10) {
        cout << "at time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        myStore.enqueue();
       
        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived" << endl;
      }
    }

    else if (storeClock > 570 && storeClock <= 720) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 25) {
        cout << "at time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        myStore.enqueue();
        
       
        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived" << endl;
      }
    }

    else if (storeClock > 720 && storeClock <= 900) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 20) {
        cout << "at time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        myStore.enqueue();
        
        
        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived" << endl;
      }
    }

    else if (storeClock > 900 && storeClock <= 1020) {
      randomNum = rand() % 100 + 1;
      if (randomNum <= 10) {
        cout << "at time: " << storeClock << " we have 1 new customer " << endl;
        customerCount++;
        myStore.enqueue();
        
        queueLength++;
      } else {
        cout << "at time: " << storeClock << " no new customer arrived" << endl;
      }
    }

    if (myStore.head != NULL) {
      if (myStore.head->orderTime == 0) {
        myStore.head->outTime = storeClock;
        myStore.head->serviceTime =
            myStore.head->outTime - myStore.head->inTime;
        cout << "service time: " << myStore.head->serviceTime << endl;
        
        serviceTimeSume += myStore.head->serviceTime;
        if (myStore.head->serviceTime < minServiceTime) {
          minServiceTime = myStore.head->serviceTime;
          time3 = myStore.head->inTime;
        }

        if (myStore.head->serviceTime > maxServiceTime) {
          maxServiceTime = myStore.head->serviceTime;
          time4 = myStore.head->inTime;
        }
      
        myStore.dequeue();
        queueLength--;
        if (myStore.head != NULL) {
          waitTimeSum += myStore.head->waitTime;
          if (myStore.head->waitTime < minWaitTime) {
            minWaitTime = myStore.head->waitTime;
            time1 = myStore.head->inTime;
          }

          if (myStore.head->waitTime > maxWaitTime) {
            maxWaitTime = myStore.head->waitTime;
            time2 = myStore.head->inTime;
          }
        }

      } else {
        myStore.head->orderTime--;
      }
    }
    queuelengthsum += queueLength;
    if (queueLength < minQueueTime) {
      minQueueTime = queueLength;
      time5 = storeClock;
    }

    if (queueLength > maxQueueTime) {
      maxQueueTime = queueLength;
      time6 = storeClock;
    }
  }
  
  cout << "customer count: " << customerCount << endl;
  cout << "average queue length: " << queuelengthsum / 1020.0 << endl;

  cout << "average customer wait time: " << waitTimeSum / customerCount << endl;
  cout << "average customer service time: " << serviceTimeSume / customerCount
       << endl;
  cout << "best case wait time: " << minWaitTime << " at time: " << time1
       << " mins" << endl;
  cout << "worst case wait time: " << maxWaitTime << " at time: " << time2
       << " mins" << endl;
  cout << "best case service time: " << minServiceTime << " at time: " << time3
       << " mins" << endl;
  cout << "worst case service time: " << maxServiceTime << " at time: " << time4
       << " mins" << endl;
  cout << "best case queue length: " << minQueueTime << " customers " << " at time: " << time5
       << " mins " << endl;
  cout << "worst case queue length: " << maxQueueTime << " customers " << " at time: " << time6
       << " mins " << endl;

  
}