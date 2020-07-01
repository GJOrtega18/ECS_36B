//
// Created by george on 4/10/19.
//

#ifndef CLASS_NOTES_MORESTRINGFUNCTIONS_H
#define CLASS_NOTES_MORESTRINGFUNCTIONS_H

#include <map>
#include <string>
#include <vector>


void lowerInPlace(std::string& string);
std::string lower(std::string string);
void stripInPlace(std::string& string, const std::string& charsToRemove = "\t,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`' ");
void lstripInPlace(std::string& string, const std::string& charsToRemove = "\t,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`' ");
void rstripInPlace(std::string& string, const std::string& charsToRemove = "\t,.:;\"|\\!@#$%^&*()_+-=[]{}<>?/~`' ");

bool wordContains(const std::string& string, char letter);

bool contains(const std::map<int, std::vector<std::string>>& wordList, std::string& word);

std::vector<std::string> split(const std::string& string, const std::string& delimiter);


#endif //CLASS_NOTES_MORESTRINGFUNCTIONS_H
