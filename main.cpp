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

  else if (method == 3){
    if (orderCost < 35){
      return 5;
    }
    else if (orderCost < 100){
      return 8;
    }
    else{
      return 0;
    }
  }
  
  else{
    return -1;
  }

}

int main()
{
  double cost;
  int method;

  cout << "Enter the cost of your order: ";
  cin >> cost;

  cout << "Enter your shipping method: ";
  cin >> method;

  double shippingFee = getShippingCost(method, cost);

  if (shippingFee == -1){
    if (method == 1 && cost < 100){
      cout << "Not available";
    }
    else{
      cout << "Bad input";
    }
  }

  double total = cost + shippingFee;
  double rounded_fee = static_cast<int>(total * 100) / 100.0;

  cout << "Total is: " << rounded_fee << endl;
}
