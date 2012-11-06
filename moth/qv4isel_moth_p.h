#ifndef QV4ISEL_MOTH_P_H
#define QV4ISEL_MOTH_P_H

#include "qv4ir_p.h"
#include "qmljs_objects.h"
#include "qv4instr_moth_p.h"

namespace QQmlJS {
namespace Moth {

class InstructionSelection : public IR::StmtVisitor
{
public:
    InstructionSelection(VM::ExecutionEngine *engine, IR::Module *module, uchar *code);
    ~InstructionSelection();

    void operator()(IR::Function *function);

protected:
    virtual void visitExp(IR::Exp *);
    virtual void visitEnter(IR::Enter *);
    virtual void visitLeave(IR::Leave *);
    virtual void visitMove(IR::Move *);
    virtual void visitJump(IR::Jump *);
    virtual void visitCJump(IR::CJump *);
    virtual void visitRet(IR::Ret *);

private:
    struct Instruction {
#define MOTH_INSTR_DATA_TYPEDEF(I, FMT) typedef InstrData<Instr::I> I;
    FOR_EACH_MOTH_INSTR(MOTH_INSTR_DATA_TYPEDEF)
#undef MOTH_INSTR_DATA_TYPEDEF
    private:
        Instruction();
    };

    void simpleMove(IR::Move *);
    void callActivationProperty(IR::Call *c);
    void callValue(IR::Call *c);
    void callProperty(IR::Call *c);
    void construct(IR::New *ctor);
    void prepareCallArgs(IR::ExprList *, quint32 &, quint32 &);

    template <int Instr>
    inline ptrdiff_t addInstruction(const InstrData<Instr> &data);
    ptrdiff_t addInstructionHelper(Instr::Type type, Instr &instr);

    VM::ExecutionEngine *_engine;
    IR::Function *_function;
    IR::BasicBlock *_block;

    QHash<IR::BasicBlock *, QVector<ptrdiff_t> > _patches;
    QHash<IR::BasicBlock *, ptrdiff_t> _addrs;

    uchar *_code;
    uchar *_ccode;
};

template<int InstrT>
ptrdiff_t InstructionSelection::addInstruction(const InstrData<InstrT> &data)
{
    Instr genericInstr;
    InstrMeta<InstrT>::setData(genericInstr, data);
    return addInstructionHelper(static_cast<Instr::Type>(InstrT), genericInstr);
}

} // namespace Moth
} // namespace QQmlJS

#endif // QV4ISEL_MOTH_P_H
