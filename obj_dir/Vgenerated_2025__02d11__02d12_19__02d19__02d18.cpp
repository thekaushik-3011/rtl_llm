// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vgenerated_2025__02d11__02d12_19__02d19__02d18__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vgenerated_2025__02d11__02d12_19__02d19__02d18::Vgenerated_2025__02d11__02d12_19__02d19__02d18(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vgenerated_2025__02d11__02d12_19__02d19__02d18::Vgenerated_2025__02d11__02d12_19__02d19__02d18(const char* _vcname__)
    : Vgenerated_2025__02d11__02d12_19__02d19__02d18(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vgenerated_2025__02d11__02d12_19__02d19__02d18::~Vgenerated_2025__02d11__02d12_19__02d19__02d18() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_debug_assertions(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);
#endif  // VL_DEBUG
void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_static(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);
void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_initial(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);
void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_settle(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);
void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);

void Vgenerated_2025__02d11__02d12_19__02d19__02d18::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vgenerated_2025__02d11__02d12_19__02d19__02d18::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_static(&(vlSymsp->TOP));
        Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_initial(&(vlSymsp->TOP));
        Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vgenerated_2025__02d11__02d12_19__02d19__02d18::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vgenerated_2025__02d11__02d12_19__02d19__02d18::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vgenerated_2025__02d11__02d12_19__02d19__02d18::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_final(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf);

VL_ATTR_COLD void Vgenerated_2025__02d11__02d12_19__02d19__02d18::final() {
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vgenerated_2025__02d11__02d12_19__02d19__02d18::hierName() const { return vlSymsp->name(); }
const char* Vgenerated_2025__02d11__02d12_19__02d19__02d18::modelName() const { return "Vgenerated_2025__02d11__02d12_19__02d19__02d18"; }
unsigned Vgenerated_2025__02d11__02d12_19__02d19__02d18::threads() const { return 1; }
void Vgenerated_2025__02d11__02d12_19__02d19__02d18::prepareClone() const { contextp()->prepareClone(); }
void Vgenerated_2025__02d11__02d12_19__02d19__02d18::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vgenerated_2025__02d11__02d12_19__02d19__02d18::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_decl_types(VerilatedFst* tracep);

void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_init_top(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root*>(voidSelf);
    Vgenerated_2025__02d11__02d12_19__02d19__02d18__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_decl_types(tracep);
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_register(Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vgenerated_2025__02d11__02d12_19__02d19__02d18::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vgenerated_2025__02d11__02d12_19__02d19__02d18::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vgenerated_2025__02d11__02d12_19__02d19__02d18___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
