#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

using ValueType = uint16_t;
using RowType = vector<ValueType>;
using MatrixType = vector<RowType>;

struct TraceResult
{
	ValueType trace;
	size_t bad_rows;
	size_t bad_columns;
};

TraceResult solve(const MatrixType& M)
{
    TraceResult r{};

    for (size_t i = 0; i < M.size(); i++) {
    	r.trace += M[i][i];
    }

	for (size_t i = 0; i < M.size(); i++) {
		set<ValueType> row_values{};
		for (size_t j = 0; j < M.size(); j++) {
			auto ins_result = row_values.insert(M[i][j]);
			if (ins_result.second == false) {
				r.bad_rows++;
				break;
			}
		}
	}

	for (size_t j = 0; j < M.size(); j++) {
		set<ValueType> col_values{};
		for (size_t i = 0; i < M.size(); i++) {
			auto ins_result = col_values.insert(M[i][j]);
			if (ins_result.second == false) {
				r.bad_columns++;
				break;
			}
		}
	}

    return r;
}

int main()
{
    size_t T;
    cin >> T;

    for (size_t t = 0; t < T; t++)
    {
        size_t N;
        cin >> N;

        MatrixType M{N, RowType(N, 0)};

        for (size_t i = 0; i < N; i++) {
        	for (size_t j = 0; j < N; j++) {
        		cin >> M[i][j];
        	}
        }

		TraceResult r = solve(M);

        cout << "Case #" << (t+1) << ": " << r.trace << " " << r.bad_rows << " " << r.bad_columns << endl;
    }

    return 0;
}
