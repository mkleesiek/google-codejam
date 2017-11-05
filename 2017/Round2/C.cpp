#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

using namespace std;

enum Direction {
    Up,
    Left,
    Down,
    Right
};

enum BeamType {
    None = 0,
    Horizontal = 1,
    Vertical = 2,
    Both = 3
};

struct Beam { int row; int col; int type; };

bool findBeam(const vector<vector<char>>& M, int r, int c, Direction dir, Beam& beam)
{
    if (r < 0 || r >= (int) M.size() || c < 0 || c >= (int) M[r].size())
        return false;

    if (M[r][c] == '|' || M[r][c] == '-') {
        beam = { r, c, (dir == Right || dir == Left) ? Horizontal : Vertical };
        return true;
    }

    if (M[r][c] == '/') {
        switch(dir) {
            case Up    : return findBeam(M, r, c+1, Right, beam);
            case Right : return findBeam(M, r-1, c, Up, beam);
            case Down  : return findBeam(M, r, c-1, Left, beam);
            case Left  : return findBeam(M, r+1, c, Down, beam);
        }
    }
    if (M[r][c] == '\\') {
        switch(dir) {
            case Up    : return findBeam(M, r, c-1, Left, beam);
            case Right : return findBeam(M, r+1, c, Down, beam);
            case Down  : return findBeam(M, r, c+1, Right, beam);
            case Left  : return findBeam(M, r-1, c, Up, beam);
        }
    }

    switch(dir) {
        case Up    : return findBeam(M, r-1, c, Up, beam);
        case Right : return findBeam(M, r, c+1, Right, beam);
        case Down  : return findBeam(M, r+1, c, Down, beam);
        case Left  : return findBeam(M, r, c-1, Left, beam);
    }

    return false;
}

bool findBeam(const vector<vector<char>>& M, int r, int c, Direction dir)
{
    Beam tmp;
    return findBeam(M, r, c, dir, tmp);
}

int main()
{
    int T = 0;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        size_t R, C;
        cin >> R >> C;

        cout << "Case #" << t << ": ";

        vector<vector<char>> M(R, vector<char>(C, 0));

        for (size_t r = 0; r < R; ++r) {
            for (size_t c = 0; c < C; ++c) {
                cin >> M[r][c];
            }
        }

        // check beam types
        vector<vector<int>> beams(R, vector<int>(C, None));

        bool invalid = false;

        for (size_t r = 0; r < R; ++r) {
            for (size_t c = 0; c < C; ++c) {
                if (M[r][c] == '|' || M[r][c] == '-') {
                    beams[r][c] = Both;
                    if (findBeam(M, r, c+1, Right) || findBeam(M, r, c-1, Left))
                        beams[r][c] &= ~Horizontal;
                    if (findBeam(M, r+1, c, Down) || findBeam(M, r-1, c, Up))
                        beams[r][c] &= ~Vertical;
                    if (beams[r][c] == None) {
                        invalid = true;
                        break;
                    }
                }
            }
        }

        if (invalid) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {

            // check cells
            vector<vector<list<Beam>>> cells(R, vector<list<Beam>>(C));

            for (size_t r = 0; r < R; ++r) {
                for (size_t c = 0; c < C; ++c) {
                    if (M[r][c] == '.') {
                        list<Beam> possibleBeams;
                        Beam beam;
                        if ((findBeam(M, r, c+1, Right, beam) && beams[beam.row][beam.col] & beam.type) || (findBeam(M, r, c-1, Left, beam) && beams[beam.row][beam.col] & beam.type))
                            possibleBeams.push_back( beam );
                        if ((findBeam(M, r+1, c, Down, beam) && beams[beam.row][beam.col] & beam.type) || (findBeam(M, r-1, c, Up, beam) && beams[beam.row][beam.col] & beam.type) )
                            possibleBeams.push_back( beam );

                        if (possibleBeams.empty()) {
                            invalid = true;
                            break;
                        }
                        if (possibleBeams.size() == 1)
                            beams[possibleBeams.front().row][possibleBeams.front().row] = possibleBeams.front().type;
                    }
                }
            }

            if (invalid) {
                cout << "IMPOSSIBLE" << endl;
            }
            else {
                cout << "POSSIBLE" << endl;
                for (size_t r = 0; r < R; ++r) {
                    for (size_t c = 0; c < C; ++c) {
                        if (M[r][c] == '|' || M[r][c] == '-') {
                            if (beams[r][c] == Horizontal)
                                cout << '-';
                            else
                                cout << '|';
                        }
                        else {
                            cout << M[r][c];
                        }
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}