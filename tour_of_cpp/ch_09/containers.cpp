#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

struct Person {
  std::string name;
  int age;
};

std::istream& operator>>(std::istream& is, Person& p) {
  std::string line;
  if (!std::getline(is, line)) return is;

  std::istringstream iss{line};
  char ch;

  if (!(iss >> ch) || ch != '{') return is;
  if (!(iss >> ch) || ch != '"') return is;

  std::getline(iss, p.name, '"');

  if (!(iss >> ch) || ch != ',') return is;
  if (!(iss >> p.age)) return is;
  if (!(iss >> ch) || ch != '}') return is;

  return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
  return os << "Name: " << p.name << ", Age: " << p.age;
}

int find_age(const std::vector<Person>& persons, const std::string& s) {
  for (const auto& person : persons) {
    if (person.name == s) {
      return person.age;
    }
  }

  return -1;
}

int main() {
  std::ifstream file{"persons.txt"};
  if (!file) {
    std::cerr << "Could not open file.\n";
    return 1;
  }

  std::vector<Person> persons;
  for (Person p; file >> p;) {
    persons.push_back(p);
  }

  for (const auto& person : persons) {
    std::cout << person << '\n';
  }

  std::cout << find_age(persons, "Karl Popper") << '\n';

  return 0;
}
