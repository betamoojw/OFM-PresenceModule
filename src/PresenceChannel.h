#pragma once
#include "OpenKNX.h"
// #include "HardwareDevices.h"

// State marker (BITFIELD !!!)
#define STATE_STARTUP 0x00000001          // startup delay for each channel
#define STATE_RUNNING 0x00000002          // this channel is running
#define STATE_MANUAL 0x00000004           // manual mode on
#define STATE_AUTO 0x00000008             // manual mode on
#define STATE_PRESENCE 0x00000010         // there is presence
#define STATE_PRESENCE_SHORT 0x00000020   // short presence evaluation
#define STATE_LOCK 0x00000040             // lock state
#define STATE_DAY_PHASE_CHANGE 0x00000080 // change day phase at desired point of time
#define STATE_DOWNTIME 0x00000100         // Downtime after leave room
#define STATE_ADAPTIVE 0x00000200         // adaptive brightness calculation
#define STATE_ADAPTIVE_READ 0x00000400    // adaptive brightness calculation
#define STATE_LEAVE_ROOM 0x00000800       // During leave room we ignore any presence signal
#define STATE_READ_REQUESTS 0x00001000    // After startup delay, we first have to process all read requests
#define STATE_KO_LUX_ON 0x00010000
#define STATE_KO_LUX 0x00020000
#define STATE_KO_PRESENCE1 0x00040000
#define STATE_KO_PRESENCE2 0x00080000
#define STATE_KO_SET_AUTO 0x00100000
#define STATE_KO_SET_MANUAL 0x00200000
#define STATE_KO_SET_ACTOR_STATE 0x00400000
#define STATE_KO_LOCK 0x00800000
#define STATE_KO_RESET 0x01000000
#define STATE_KO_DAY_PHASE 0x02000000
#define STATE_KO_SCENE 0x04000000
#define STATE_KO_CHANGE_STATE 0x08000000

// Value marker (BITFIELD)
#define PM_BIT_OUTPUT_SET 1         // output value to send
#define PM_BIT_OUTPUT_WRITTEN 2     // output value sent
#define PM_BIT_OUTPUT_FORCE 4       // output value sent
#define PM_BIT_DISABLE_BRIGHTNESS 8 // Brightness off temporarily disabled

#define PM_VAL_OUTPUT_MASK (PM_BIT_OUTPUT_SET | PM_BIT_OUTPUT_WRITTEN)

#define PM_VAL_ActiveNo 0
#define PM_VAL_ActiveYes 1
#define PM_VAL_ActiveDisabled 2

// and we also define all enum values for PM
#define VAL_PM_LedOff 0
#define VAL_PM_LedMove 1
#define VAL_PM_LedPresence 2
#define VAL_PM_LedKnx 3

// brightness auto off
#define VAL_PM_LuxNoOff 0
#define VAL_PM_LuxAbsoluteOff 1
#define VAL_PM_LuxAdaptiveOff 2

// presence usage
#define VAL_PM_PresenceUsageNone 0
#define VAL_PM_PresenceUsageMove 1
#define VAL_PM_PresenceUsagePresence 2

// output index, there are 2 outputs
#define VAL_PM_Output1Index 0
#define VAL_PM_Output2Index 1

// output types
#define VAL_PM_Switch 0
#define VAL_PM_Value 1
#define VAL_PM_Scene 2
#define VAL_PM_Dim 3

// lock type
#define VAL_PM_LockTypeNone 0
#define VAL_PM_LockTypePriority 1
#define VAL_PM_LockTypeLock 2

// lock output
#define VAL_PM_LockOutputNone 0
#define VAL_PM_LockOutputOff 1
#define VAL_PM_LockOutputOn 2
#define VAL_PM_LockOutputCurrent 3

// day phases
#define VAL_PM_DAY 0
#define VAL_PM_NIGHT 1
#define VAL_PM_MORNING 2
#define VAL_PM_EVENING 3

// scene actions
#define VAL_PM_SA_None 0
#define VAL_PM_SA_ChangeBrightness 1
#define VAL_PM_SA_AutoOff 2
#define VAL_PM_SA_AutoOn 3
#define VAL_PM_SA_ManualOff 4
#define VAL_PM_SA_ManualOn 5
#define VAL_PM_SA_LockOff 6
#define VAL_PM_SA_LockOn 7
#define VAL_PM_SA_Lock 8
#define VAL_PM_SA_UnlockWithState 9
#define VAL_PM_SA_Unlock 10
#define VAL_PM_SA_Reserve1 11
#define VAL_PM_SA_Reserve2 12
#define VAL_PM_SA_Reserve3 13
#define VAL_PM_SA_LeaveRoom 14
#define VAL_PM_SA_Reset 15
#define VAL_PM_SA_Phase1 16
#define VAL_PM_SA_Phase2 17
#define VAL_PM_SA_Phase3 18
#define VAL_PM_SA_Phase4 19
#define VAL_PM_SA_ForcePhase1 20
#define VAL_PM_SA_ForcePhase2 21
#define VAL_PM_SA_ForcePhase3 22
#define VAL_PM_SA_ForcePhase4 23
#define VAL_PM_SA_ManualActive 24
#define VAL_PM_SA_ManualInactive 25

// leave room modes
#define VAL_PM_LRM_None 0
#define VAL_PM_LRM_Downtime 1
#define VAL_PM_LRM_DowntimeReset 2
#define VAL_PM_LRM_MoveDowntime 3
#define VAL_PM_LRM_MoveDowntimeReset 4

// available presence inputs
#define VAL_PM_PI_None 0
#define VAL_PM_PI_Presence 1
#define VAL_PM_PI_Move 2
#define VAL_PM_PI_PresenceMove 3
#define VAL_PM_PI_PresencePresence 4

// HF Sensor
#define VAL_PM_PS_None 0
// #define VAL_PM_PS_Pir_Digital 1
#define VAL_PM_PS_Hf_MR24xxB1 2
#define VAL_PM_PS_Hf_HLKLD2420 3
// #define VAL_PM_PS_Hf_HLKLD2420_Pir_Digital 4
// #define VAL_PM_PS_Hf_HLKLD2420_Pir_Analog 5

// PIR Sensor
#define VAL_PM_PS_None 0
#define VAL_PM_PS_Pir_Digital 1
#define VAL_PM_PS_Pir_Analog 2

// PIR Hardware
#define VAL_PM_PIR_Analog_Trigger_Min 390
#define VAL_PM_PIR_Analog_Trigger_Max 940

// Brightness Hardware
#define VAL_PM_LUX_None 0
#define VAL_PM_LUX_VEML 1
#define VAL_PM_LUX_OPT 2

// Full- or half-automatic function of a day phase
#define VAL_PM_PHASE_FULL 0
#define VAL_PM_PHASE_HALF_ON 1
#define VAL_PM_PHASE_HALF_OFF 2

// forward declaration
class Presence;

class PresenceChannel : public OpenKNX::Channel
{
  private:
    uint8_t mCurrentDayPhase = 0; // zero based
    uint8_t mNextDayPhase = 0;    // zero based
    bool mHardwarePresence = false;
    bool mHardwareMove = false;
    uint32_t mBrightnessPollDelay = 0;

    uint32_t calcParamIndex(uint16_t iParamIndex, bool iWithPhase);
    uint16_t calcKoNumber(uint8_t iKoIndex);
    int8_t calcKoIndex(uint16_t iKoNumber);
    GroupObject *getKo(uint8_t iKoIndex);

    bool paramBit(uint16_t iParamIndex, uint8_t iParamMask, bool iWithPhase = false);
    uint8_t paramByte(uint16_t iParamIndex, uint8_t iParamMask, uint8_t iParamShift, bool iWithPhase = false);
    uint8_t paramByte(uint16_t iParamIndex, bool iWithPhase = false);
    uint16_t paramWord(uint16_t iParamIndex, bool iWithPhase = false);
    uint32_t paramInt(uint16_t iParamIndex, bool iWithPhase = false);

    uint32_t paramTimeDelay(uint16_t iParamIndex, bool iWithPhase = false, bool iAsSeconds = false);

    void startStartupDelay();
    void processStartupDelay();
    void startReadRequests();
    void processReadRequests();
    void sendReadRequest(uint8_t iKoIndex);
    void startRunning();

    bool getRawPresence(bool iJustMove = false);
    bool getHardwarePresence(bool iJustMove = false);
    void startHardwarePresence();
    void startPresencePrepare(uint32_t iState);
    void processPresencePrepare(uint32_t iState);
    void startPresenceTrigger(bool iManual);
    void startPresence(bool iIsTrigger, bool iIsKeepAlive, GroupObject *Ko);
    void startPresence(bool iForce, bool iManual);
    void processPresence();
    void endPresence(bool iSend = true);
    void startPresenceShort();
    void processPresenceShort();
    void endPresenceShort();
    void onPresenceBrightnessChange(bool iOn);
    void onPresenceChange(bool iOn);

    void startSceneCommand();
    void processSceneCommand();
    void startLeaveRoom(bool iSuppressOutput);
    void processLeaveRoom();
    void endLeaveRoom();
    bool isLeaveRoom();
    void startDowntime();
    void processDowntime();
    void startAutoPrepare();
    void processAutoPrepare();
    void startAuto(bool iOn, bool iSuppressOutput);
    void processAuto();
    void startManualPrepare();
    void processManualPrepare();
    void startManual(bool iOn, bool iSuppressOutput);
    void processManual();
    void onManualChange(bool iOn);
    void startLock();
    void processLockPrepare();
    void processLock();
    void onLock(bool iLockOn, uint8_t iLockOnSend, uint8_t iLockOffSend);
    void startReset();
    void processReset();
    void onReset();

    void startActorState();
    void processActorState();

    float getRawBrightness();
    void startHardwareBrightness();
    void startBrightnessPrepare();
    void processBrightnessPrepare();
    void startBrightness();
    void processBrightness();
    void disableBrightness(bool iOn);
    void startAdaptiveBrightness();
    void processAdaptiveBrightness();
    void startBrightnessOff();
    void processBrightnessOff();

    int8_t getDayPhaseFromKO();
    void startDayPhasePrepare();
    void processDayPhasePrepare();
    void startDayPhase(uint8_t iPhase, bool iForce = false);
    void processDayPhase();
    void onDayPhase(uint8_t iPhase, bool iIsStartup = false);

    void startOutput(bool iOn);
    void forceOutput(bool iOn);
    void syncOutput();
    void processOutput();
    void onOutput(bool iOutputIndex, bool iOn);

    void prepareInternalKo();
    const std::string name() override;

  protected:
    // static
    static uint8_t sDayPhaseParameterSize; // memory block size of day phase parameters, calculated in setup

    // instance
    uint32_t pCurrentState = 0;
    uint32_t pCurrentValue = 0;
    uint32_t pOnDelay = 0;
    uint32_t pReadRequestDelay = 0;
    uint16_t pReadRequestPause = 200;
    uint8_t pReadRequestCounter = 0;
    uint32_t pPresenceDelayTime = 0;      // Nachlaufzeit
    uint32_t pPresenceShortDelayTime = 0; // Kurze Anwesenheit Nachlaufzeit
    uint32_t pManualFallbackTime = 0;     // Rückfallzeit aus Manuell-Modus
    uint32_t pOutput1CyclicTime = 0;      // Zyklisch senden Ausgang 1
    uint32_t pOutput2CyclicTime = 0;      // Zyklisch senden Ausgang 2
    uint32_t pLockDelayTime = 0;          // Rückfallzeit Sperre/Zwangsführung
    uint32_t pDowntimeDelayTime = 0;      // Totzeit
    uint32_t pAdaptiveDelayTime = 0;      // adaptive brightness calculation delay
    uint32_t pBrightnessOffDelayTime = 0; // brightness off delay
    uint8_t pLeaveRoomMode = 0;           // used for leave room SM
    uint8_t pLastLockState = 255;         // ensures sending just changed Lock states

  public:
    PresenceChannel(uint8_t iChannelNumber);
    ~PresenceChannel();

    static void setDayPhaseParameterSize(uint8_t iSize);

    void processInputKo(GroupObject &iKo, int8_t iKoIndex = -1);
    bool processCommand(const std::string iCmd, bool iDebugKo);
    void setup();
    void loop();
};
