/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:20:20 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/15 14:20:23 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>
#include <string>

int main(void) {

  std::cout << "Test1: non-const int-array" << std::endl;
  int arr_int[] = {0, 1, 2, 3, 4};
  std::cout << "show values before add - passing non-const parameter"
            << std::endl;
  iter(arr_int, 5, show<int>);
  std::cout << std::endl;
  iter(arr_int, 5, add<int>);
  std::cout << "show values after add - passing const parameter" << std::endl;
  iter(arr_int, 5, show<const int>);
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------------"
               "-------------------"
            << std::endl;

  std::cout << "Test2: const int-array" << std::endl;
  const int const_arr_int[] = {0, 1, 2, 3, 4};
  std::cout << "show values by iter - passing const parameter" << std::endl;
  iter(const_arr_int, 5, show<const int>);
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------------"
               "-------------------"
            << std::endl;

  std::cout << "Test3: non-const float-array" << std::endl;
  float arr_float[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f};
  std::cout << "show values before add - passing non-const parameter"
            << std::endl;
  iter(arr_float, 5, show<float>);
  std::cout << std::endl;
  iter(arr_float, 5, add<float>);
  std::cout << "show values after add - passing const parameter" << std::endl;
  iter(arr_float, 5, show<const float>);
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------------"
               "-------------------"
            << std::endl;

  std::cout << "Test4: const float-array" << std::endl;
  const float const_arr_float[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f};
  std::cout << "show values by iter - passing const parameter" << std::endl;
  iter(const_arr_float, 5, show<const float>);
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------------"
               "-------------------"
            << std::endl;

  std::cout << "Test5: std::string(class object) array" << std::endl;
  std::string str_array[] = {"Hello", "World", "Have", "a good day"};
  std::cout << "show values by iter" << std::endl;
  iter(str_array, 4, show<std::string>);
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------------"
               "-------------------"
            << std::endl;

  std::cout << "Test6: check error handling" << std::endl;
  std::cout << "Passing NULL to the first parameter" << std::endl;
  int *arr = NULL;
  iter(arr, 5, add<int>);
  std::cout << "Passing NULL to the third parameter" << std::endl;
  void (*ptr)(int) = NULL;
  iter(arr_int, 5, ptr);
  std::cout << "---------------------------------------------------------------"
               "-------------------"
            << std::endl;

  return 0;
}
