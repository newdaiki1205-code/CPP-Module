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
#include <string>

int main(void)
{
    int arr_int[] = {0, 1, 2, 3, 4};
    float arr_float[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f};
    double arr_double[] = {0.01, 11.2, 22.3, 33.4, 44.5};
    
    std::cout << "Test1: int-array" << std::endl;
    std::cout << "show values before iter - passing non-const parameter" << std::endl;
    iter(arr_int, 5, show<int>);
    std::cout << std::endl;
    iter(arr_int, 5, add<int>);
    std::cout << "show values after iter - passing const parameter" << std::endl;
    iter(arr_int, 5, show<const int>);
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    
    std::cout << "Test2: float-array" << std::endl;
    std::cout << "show values before iter - passing non-const parameter" << std::endl;
    iter(arr_float, 5, show<float>);
    std::cout << std::endl;
    iter(arr_float, 5, add<float>);
    std::cout << "show values after iter - passing const parameter" << std::endl;
    iter(arr_float, 5, show<const float>);
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------------------" << std::endl;
  
    std::cout << "Test3: double-array" << std::endl;
    std::cout << "show values before iter - passing non-const parameter" << std::endl;
    iter(arr_double, 5, show<double>);
    std::cout << std::endl;
    iter(arr_double, 5, add<double>);
    std::cout << "show values after iter - passing const parameter" << std::endl;
    iter(arr_double, 5, show<const double>);
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------------------------------" << std::endl;

    return 0;
}
