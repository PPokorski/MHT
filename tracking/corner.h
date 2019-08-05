#ifndef CORNER_H
#define CORNER_H

#include "mht/list.h"        // for DLISTnode
#include <vector>		// for std::vector<>

/*-----------------------------------------------*
 * Data structures for storing input corner data
 *-----------------------------------------------*/
class CORNER:public DLISTnode
{
public:
    double x,y;
    int m_frameNo;
    size_t m_cornerID;

    CORNER(const double &a, const double &b, const int &f,const size_t &cornerID):
        DLISTnode(),
        x(a),y(b),
        m_frameNo(f),
        m_cornerID(cornerID)
    {
    }

protected:
    MEMBERS_FOR_DLISTnode(CORNER)

};


class CORNERLIST: public DLISTnode
{
public:
    int ncorners;
    std::list<CORNER> list;
    float m_dT;
    CORNERLIST(int npts, float deltaT=1.0):
        ncorners(npts), list(), m_dT(deltaT), DLISTnode()
    {
    }

protected:
    MEMBERS_FOR_DLISTnode(CORNERLIST)
};



#endif
