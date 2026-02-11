#include <iostream>

using namespace std;

double getShippingCost(int method, double orderCost){
  if (method == 1){
    if (orderCost < 100){
      return -1;
    }
    else if (orderCost < 500){
      return 50;
    }
    else{
      return 0.1 * orderCost;
    }
  }

  else if (method == 2){
    if (orderCost <= 300){
      return 0.02 * orderCost + 10;
    }
    else{
      return 0;
    }
  }

  

}

int main()
{
  
}
