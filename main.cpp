#include <iostream>

using namespace std;

/**
 * @brief Get the Shipping Cost of order
 * 
 * shipping methods:
 * 1 = drone
 * 2 = 2-day
 * 3 = standard
 * 
 * @param method int representing the shipping method
 * @param orderCost cost of the order
 * @return shipping cost as double, or -1 if method is not 1, 2, or 3, 
 *              or if drone delivery selected when ordercost < 100
 */

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
  bool skip = false;

  cout << "Enter the cost of your order: ";
  cin >> cost;

  cout << "Enter your shipping method: ";
  cin >> method;

  if (cost >= 0){
    double shippingFee = getShippingCost(method, cost);
    if (static_cast<int>(shippingFee) == -1){
      if (method == 1 && cost < 100){
        cout << "Not available" << endl;
        skip = true;
      }
      else{
        cout << "Bad Input";
        skip = true;
      }
    }

    double total = cost + shippingFee;
    double rounded_fee = static_cast<int>(total * 100) / 100.0;

    if (!skip){
      cout << "Total is $" << rounded_fee << endl;
    }
  }
  else{
    cout << "Bad Input" << endl;
  }
}
