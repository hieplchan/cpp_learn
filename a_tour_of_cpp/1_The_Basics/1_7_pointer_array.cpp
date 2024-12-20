#include <vector>

char v[6];
char* p1;
char* p2 = nullptr;

/**
In expression:  & = address of, * = content of
In declaration: & = reference to
**/

char* p2 = &v[3];
char v1 = *p2;

/**
reference = pointer, but dont need to use prefix *,
and can not change pointed object ofter initialization,
**/
// pass by reference -> do not copy
// const -> do not change v inside this func
void sort(const std::vector<int>& v);