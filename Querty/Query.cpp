#include "Query.h"
#include "TextQuery.h"
#include "include.h"

using namespace std;





QueryResult NotQuery::eval(const TextQuery &text) const 
{
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();

	for(size_t i = 0; i != sz; ++i)
	{
		if(beg == end || *beg != i) 
			ret_lines->insert(i);
		else if( beg != end)
			++beg;
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}


QueryResult AndQuery::eval(const TextQuery &text) const 
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>();

	set_intersection( left.begin(), left.end(),
			  right.begin(), right.end(),
			  inserter(*ret_lines, ret_lines->begin() ) );
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult OrQuery::eval(const TextQuery& text) const 
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

