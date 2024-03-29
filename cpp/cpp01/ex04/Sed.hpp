/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:48:19 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/17 14:48:20 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed
{
    private:
        std::string s1;
        std::string s2;
        std::ifstream ifs;
        std::ofstream ofs;
    public:
        Sed(std::string input, std::string s1, std::string s2);
        ~Sed();
        void replace();
        void replaceStr(std::string *replaced);
};

#endif