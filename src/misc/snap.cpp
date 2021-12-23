#include "llvm/Analysis/Passes.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Scalar.h"

....static llvm::ExecutionEngine *TheExecutionEngine;

exec_lava()
{
    ... witch(lavaOp)

        ... case LENATIVEPLAN :
        /* prepare native plan execute context. */
        llvm::InitializeNativeTarget();
    llvm::LLVMContext &Context = llvm::getGlobalContext();
    ....
        /*
    ** call lava plan's native compile method to
    ** generate LLVM IR.
    */
        void *PlanPtr = emit->LePlanNative();
    // Cast it to the right type (takes no arguments, returns an int) so we
    // can call it as a native function.
    int (*FP)() = (int (*)())(intptr_t)PlanPtr;
    // execute the compiled query plan
    ret = FP();
    ... TheExecutionEngine->freeMachineCodeForFunction(FooF);
    delete TheExecutionEngine;
    ...
}

void *
LeEmitOp::LePlanNative()
{
    llvm::InitializeNativeTarget();
    llvm::LLVMContext &Context = llvm::getGlobalContext();

    // Create some module to put our function into it.
    llvm::Module *M = new llvm::Module("plan1", Context);

    // Create the add1 function entry and insert this entry into module M.  The
    // function will have a return type of "int" and take an argument of "int".
    // The '0' terminates the list of argument types.
    llvm::Function *Add1F =
        llvm::cast<llvm::Function>(M->getOrInsertFunction("add1", llvm::Type::getInt32Ty(Context), llvm::Type::getInt32Ty(Context),
                                                          (llvm::Type *)0));

    // Add a basic block to the function. As before, it automatically inserts
    // because of the last argument.
    llvm::BasicBlock *BB = llvm::BasicBlock::Create(Context, "EntryBlock", Add1F);

    // Get pointers to the constant `1'.
    llvm::Value *One = llvm::ConstantInt::get(llvm::Type::getInt32Ty(Context), 1);

    // Get pointers to the integer argument of the add1 function...
    assert(Add1F->arg_begin() != Add1F->arg_end()); // Make sure there's an arg
    llvm::Argument *ArgX = Add1F->arg_begin();      // Get the arg
    ArgX->setName("AnArg");                         // Give it a nice symbolic name for fun.

    // Create the add instruction, inserting it into the end of BB.
    llvm::Instruction *Add = llvm::BinaryOperator::CreateAdd(One, ArgX, "addresult", BB);

    // Create the return instruction and add it to the basic block
    llvm::ReturnInst::Create(Context, Add, BB);

    // Now, function add1 is ready.

    // Now we going to create function `foo', which returns an int and takes no
    // arguments.
    llvm::Function *FooF =
        llvm::cast<llvm::Function>(M->getOrInsertFunction("foo", llvm::Type::getInt32Ty(Context), (llvm::Type *)0));

    // Add a basic block to the FooF function.
    BB = llvm::BasicBlock::Create(Context, "EntryBlock", FooF);

    // Get pointers to the constant `10'.
    llvm::Value *Ten = llvm::ConstantInt::get(llvm::Type::getInt32Ty(Context), 10);

    // Pass Ten to the call call:
    llvm::CallInst *Add1CallRes = llvm::CallInst::Create(Add1F, Ten, "final", BB);
    //Add1CallRes->setTailCall(true);

    // Create the return instruction and add it to the basic block.
    llvm::ReturnInst::Create(Context, Add1CallRes, BB);

    // Validate the generated code, checking for consistency.
    llvm::verifyFunction(*FooF);

    // Now we create the JIT.
    TheExecutionEngine = llvm::EngineBuilder(M).create();

    llvm::FunctionPassManager OurFPM(M);

    // Set up the optimizer pipeline.  Start with registering info about how the
    // target lays out data structures.
    OurFPM.add(new llvm::DataLayout(*TheExecutionEngine->getDataLayout()));
    // Provide basic AliasAnalysis support for GVN.
    OurFPM.add(llvm::createBasicAliasAnalysisPass());
    // Do simple "peephole" optimizations and bit-twiddling optzns.
    OurFPM.add(llvm::createInstructionCombiningPass());
    // Reassociate expressions.
    OurFPM.add(llvm::createReassociatePass());
    // Eliminate Common SubExpressions.
    OurFPM.add(llvm::createGVNPass());
    // Simplify the control flow graph (deleting unreachable blocks, etc).
    OurFPM.add(llvm::createCFGSimplificationPass());

    OurFPM.doInitialization();

    // Optimize the function.
    OurFPM.run(*FooF);

    void *FPtr = TheExecutionEngine->getPointerToFunction(FooF);

    return FPtr;
}