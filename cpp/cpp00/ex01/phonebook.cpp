/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:33:24 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/03/14 19:16:24 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;
	int			idx = 0, cnt = 0;

	for (;;)
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			Contact contact;
			contact.create();
			idx %= 8;
			phonebook.add(idx, contact);
			idx++;
			cnt++;
		}
		else if (cmd == "SEARCH")
		{
			phonebook.show(cnt);
		}
		else if (cmd == "EXIT")
			exit(0);
	}
	return 0;
}