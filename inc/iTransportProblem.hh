#ifndef ITRANSPORTPROBLEM_HH
#define ITRANSPORTPROBLEM_HH
template<typename T>
class iTransportProblem
{
public:
  virtual void upLeftCorner()=0;
  virtual void minimalElement()=0;
};
#endif
