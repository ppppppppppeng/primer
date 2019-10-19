#include "include.h"
#include "StrVec.h"

using namespace std;

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first++, s); 
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
	if(elements)
	{
		for(auto p = first_free; p != elements;)
			alloc.destory(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::Strvec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.seconds;
	return *this;
}
StrVec::~StrVec()
{
	free();
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = elements;

	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity; 

}
StrVec::StrVec(StrVec &&s) noexcept
: elements(s.elements), first_free(s.first_free),cap(s.cap)
{
	s.element = s.first_free = s.cap= nullptr;
}
StrVec & StrVec::operator=(StrVec &&) noexcept
{
	if(this != &rhs)
	{
		free();
		elements = rhs.element;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
