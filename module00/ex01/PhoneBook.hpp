/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:18:21 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 13:18:22 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "General.hpp"
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact array[8];
        int i;

    public:
        void add_info();
        void search_info();
        void fill_info(std::string (&info)[5]);
        void display_subinfo(std::string src);

        PhoneBook()
        {
            i = 0;
        }
        ~PhoneBook(){}
};

#endif