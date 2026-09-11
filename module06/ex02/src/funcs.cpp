/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42.vienna.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:12:09 by dshirais          #+#    #+#             */
/*   Updated: 2026/09/11 17:09:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/Base.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

Base* generate(void)
{
  int i;
  
  srand(time(0));
  i = rand() % 3;
  switch (i)
  {
    case 0:
      Base* res = new A();
      return res;
    case 1:
      Base* res = new B();
      return res;
    case 2:
      Base* res = new C();
      return res;
  }
}

