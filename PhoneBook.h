#pragma once
#include <vector>
#include <string>
#include <set>
#include <optional>
#include <iosfwd>
#include "iterator_range.h"
// #include "contact.pb.h"
#include <string_view>

struct Contact
{
    std::string name;
    std::vector<std::string> ;
};

class PhoneBook
{
public:
    explicit PhoneBook(const std::vector<Contact>& contacts);
	

    using ContactsIterator = std::multiset<Contact>::const_iterator;
    using ContactRange = IteratorRange<ContactsIterator>;
    [[nodiscard]] ContactRange FindByNamePrefix(std::string_view name_prefix) const;

    void SaveTo(std::ostream& output) const;

private:
    str::multiset<Contact> contacts_;
};

PhoneBook DeserializePhoneBook(std::istream& input);

void TestPhoneBook();