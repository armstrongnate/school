#include library_needed_for_pair
namespace cgl {
  namespace a2 {
    enum {
      I_UNKNOWN;
      I_PLAIN,
      I_MUD,
      I_ROCKS,
      I_WALL,
      I_CLIFF
    };

    class Cell {
      public:
        Cell();
        Cell(int id, double x, double y, double z, int n, int s, int e, int w);
        int id; // id == -1 for non-cells
        double x, y, z;
        int n, s, e, w;
    };

    class Model {
      public:
        Model();
        ~Model();
        bool AddCell(int id, double x, double y, double z, int n, int s, int e, int w);
        Cell FindCell(double x, double y);
        static int InterfaceStringToInt(const char *s);
      protected:
      private:
        int DoubleToInt(const double d) const;
        std::map<std::pair<int,int>, Cell> cells;
    }
  }
}

// Storing our cells
// We need a way to store our cells in a way that we can look them
// up using x and y efficiently without running into trouble with doubles.
// Arrays and vectors are a bad idea because of negative numbers and other
// issues.
// Use a Map! we could use a std pair as the key.
//
// DoubleToInt
// ((int)(x + 1)) / 1000
