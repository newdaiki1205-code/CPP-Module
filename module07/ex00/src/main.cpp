/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiraishidaisei <dshirais@student.42vienn  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:57:19 by shiraishidais     #+#    #+#             */
/*   Updated: 2026/09/15 13:40:53 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/funcs.hpp"
#include <iostream>

int main(void)
{
  std::cout << "Test from the subject" << std::endl;
  int a = 2;
  int b = 3;
  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

  std::cout << std::endl;
  std::cout << "----------------------------------------------------------------------------------" << std::endl;

  std::cout << "Case Int" << std::endl;
  int ai = 1;
  int bi = 42;
  std::cout << "Before swap: a = " << ai << ", b = " << bi << std::endl;
  swap<int>(ai, bi);
  std::cout << "After swap: a = " << ai << ", b = " << bi << std::endl;

  std::cout << std::endl;

  std::cout << "The smallest number is " << min<int>(ai, bi) << std::endl;
  std::cout << "The greatest number is " << max<int>(ai, bi) << std::endl;

  std::cout << std::endl;
  std::cout << "----------------------------------------------------------------------------------" << std::endl;

  std::cout << "Case char" << std::endl;
  char ac = 'a';
  char bc = 'b';
  std::cout << "Before swap: a = " << ac << ", b = " << bc << std::endl;
  swap<char>(ac, bc);
  std::cout << "After swap: a = " << ac << ", b = " << bc << std::endl;

  std::cout << std::endl;

  std::cout << "The smallest char is " << min<char>(ac, bc) << std::endl;
  std::cout << "The greatest char is " << max<char>(ac, bc) << std::endl;

  std::cout << std::endl;
  std::cout << "----------------------------------------------------------------------------------" << std::endl;

  std::cout << "Case float" << std::endl;
  float af = 3.14f;
  float bf = -42.42f;
  std::cout << "Before swap: a = " << af << ", b = " << bf << std::endl;
  swap<float>(af, bf);
  std::cout << "After swap: a = " << af << ", b = " << bf << std::endl;

  std::cout << std::endl;

  std::cout << "The smallest number is " << min<float>(af, bf) << std::endl;
  std::cout << "The greatest number is " << max<float>(af, bf) << std::endl;

  std::cout << std::endl;
  std::cout << "----------------------------------------------------------------------------------" << std::endl;

  std::cout << "Case double" << std::endl;
  double ad = 1.23;
  double bd = 9.87;
  std::cout << "Before swap: a = " << ad << ", b = " << bd << std::endl;
  swap<double>(ad, bd);
  std::cout << "After swap: a = " << ad << ", b = " << bd << std::endl;

  std::cout << std::endl;
  std::cout << "The smallest number is " << min<double>(ad, bd) << std::endl;
  std::cout << "The greatest number is " << max<double>(ad, bd) << std::endl;

  std::cout << std::endl;
  std::cout << "----------------------------------------------------------------------------------" << std::endl;

  std::cout << "Case equal" << std::endl;
  int ae = 42;
  int be = 42;

  std::cout << "The values are equal: a = " << ae << ", b = " << be << std::endl;

  std::cout << std::endl;
  std::cout << "The smallest number is " << min<int>(ae, be) << std::endl;
  std::cout << "The greatest number is " << max<int>(ae, be) << std::endl;

  return 0;
}










