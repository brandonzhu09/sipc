#pragma once

#include "TipTypeVisitor.h"
#include "TypeConstraintVisitor.h"

/*! \brief Produces a type with designated variable substitutions.
 */
class Substituter : public TipTypeVisitor {
  TipVar *target;
  std::shared_ptr<TipType> substitution;

protected:
  std::vector<std::shared_ptr<TipType>> visitedTypes;
  Substituter() = default;

public:
  Substituter(TipVar *t, std::shared_ptr<TipType> s)
      : target(t), substitution(s) {}

  /*! \brief Substitute for instances of variable in a target type.
   *
   * This function requires the substitution to be a shared_ptr so that it can
   * be directly substituted for the variable without having to be
   * reconstructed. This simplifies things when the substitution is a complex
   * type expression. It does lead to a bit of asymmetry in the API and it will
   * lead to sharing among type expressions, which is why we use shared_ptrs.
   *
   * \param t The type on which substitution is performed.
   * \param v The target variable.
   * \param s The subtitution.
   * \return An equivalent type with no occurrences of the target variable.
   */
  static std::shared_ptr<TipType> substitute(TipType *t, TipVar *v,
                                             std::shared_ptr<TipType> s);

  std::shared_ptr<TipType> getResult();

  virtual void endVisit(TipAlpha *element) override;
  virtual void endVisit(TipFunction *element) override;
  virtual void endVisit(TipInt *element) override;
  virtual void endVisit(TipMu *element) override;
  virtual void endVisit(TipRecord *element) override;
  virtual void endVisit(TipAbsentField *element) override;
  virtual void endVisit(TipRef *element) override;
  virtual void endVisit(TipVar *element) override;

  virtual void endVisit(TipBool *element) override;
  virtual void endVisit(TipArr *element) override;
};
