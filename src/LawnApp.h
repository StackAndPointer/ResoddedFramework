#ifndef __LAWNAPP_H__
#define __LAWNAPP_H__

#include "ConstEnums.h"
#include "SexyAppFramework/SexyApp.h"

class Achievements;
class Board;
class GameSelector;
class ChallengeDefinition;
class SeedChooserScreen;
class AwardScreen;
class CreditScreen;
class TodFoley;
class PoolEffect;
class ZenGarden;
class PottedPlant;
class EffectSystem;
class TodParticleSystem;
class Reanimation;
class ReanimatorCache;
class ProfileMgr;
class PlayerInfo;
class Music;
class TitleScreen;
class PopDRMComm;
class ChallengeScreen;
class StoreScreen;
class AlmanacDialog;
class TypingCheck;
#if LAWN_DEBUG_TOOLS
class DebuggerWindow;
#endif

namespace Sexy
{
class Dialog;
class Graphics;
class ButtonWidget;
class Version;
}; // namespace Sexy

enum FoleyType;

using namespace Sexy;

typedef std::list<ButtonWidget *> ButtonList;
typedef std::list<Image *> ImageList;

class LevelStats
{
  public:
	int mUnusedLawnMowers;

  public:
	LevelStats()
	{
		Reset();
	}
	inline void Reset()
	{
		mUnusedLawnMowers = 0;
	}
};

class LawnApp : public SexyApp
{
  public:
	Board *mBoard;
	TitleScreen *mTitleScreen;
	GameSelector *mGameSelector;
	SeedChooserScreen *mSeedChooserScreen;
	AwardScreen *mAwardScreen;
	CreditScreen *mCreditScreen;
	ChallengeScreen *mChallengeScreen;
	TodFoley *mSoundSystem;
	ButtonList mControlButtonList;
	ImageList mCreatedImageList;
	std::string mReferId;
	std::string mRegisterLink;
	std::string mMod;
	bool mRegisterResourcesLoaded;
	bool mTodCheatKeys;
	GameMode mGameMode;
	GameScenes mGameScene;
	bool mLoadingZombiesThreadCompleted;
	bool mFirstTimeGameSelector;
	int mGamesPlayed;
	int mMaxExecutions;
	int mMaxPlays;
	int mMaxTime;
	bool mEasyPlantingCheat;
	PoolEffect *mPoolEffect;
	ZenGarden *mZenGarden;
	EffectSystem *mEffectSystem;
	ReanimatorCache *mReanimatorCache;
	ProfileMgr *mProfileMgr;
	PlayerInfo *mPlayerInfo;
	Achievements *mAchievements;
	LevelStats *mLastLevelStats;
	bool mCloseRequest;
	int mAppCounter;
	Music *mMusic;
	ReanimationID mCrazyDaveReanimID;
	CrazyDaveState mCrazyDaveState;
	int mCrazyDaveBlinkCounter;
	ReanimationID mCrazyDaveBlinkReanimID;
	int mCrazyDaveMessageIndex;
	SexyString mCrazyDaveMessageText;
	int mAppRandSeed;
#if SEXY_USE_DRM
	PopDRMComm *mDRM;
#endif
#if LAWN_DEBUG_TOOLS
	bool mDebuggerEnabled;
	DebuggerWindow *mDebugWindow;
#endif
	int64_t mSessionID;
	int mPlayTimeActiveSession;
	int mPlayTimeInactiveSession;
	BoardResult mBoardResult;
	bool mSawYeti;
	TypingCheck *mKonamiCheck;
	TypingCheck *mMustacheCheck;
	TypingCheck *mMoustacheCheck;
	TypingCheck *mSuperMowerCheck;
	TypingCheck *mSuperMowerCheck2;
	TypingCheck *mFutureCheck;
	TypingCheck *mPinataCheck;
	TypingCheck *mDanceCheck;
	TypingCheck *mDaisyCheck;
	TypingCheck *mSukhbirCheck;
	bool mMustacheMode;
	bool mSuperMowerMode;
	bool mFutureMode;
	bool mPinataMode;
	bool mDanceMode;
	bool mDaisyMode;
	bool mSukhbirMode;
	TrialType mTrialType;
	bool mDebugTrialLocked;
	bool mMuteSoundsForCutscene;

	static Version gResoddedVersion;


  public:
	LawnApp();
	virtual ~LawnApp();

	/// @brief Close the Options Dialog
	/// @return True if it exists
	bool KillNewOptionsDialog();

	virtual void GotFocus();

	virtual void LostFocus();

	virtual void InitHook();

	virtual void WriteToRegistry();

	virtual void ReadFromRegistry();

	virtual void LoadingThreadProc();

	virtual void LoadingCompleted();

	virtual void LoadingThreadCompleted();

	virtual void URLOpenFailed(const std::string &theURL);

	virtual void URLOpenSucceeded(const std::string &theURL);

	virtual bool OpenURL(const std::string &theURL, bool shutdownOnOpen);

	virtual bool DebugKeyDown(int theKey);

	virtual void HandleCmdLineParam(const std::string &theParamName, const std::string &theParamValue);

	void ConfirmQuit();

	void ConfirmCheckForUpdates()
	{
		;
	}

	void CheckForUpdates()
	{
		;
	}

	void DoUserDialog();

	void FinishUserDialog(bool isYes);

	void DoCreateUserDialog();

	void DoCheatDialog();

	void FinishCheatDialog(bool isYes);

	void FinishCreateUserDialog(bool isYes);


	void DoConfirmDeleteUserDialog(const SexyString &theName);

	void FinishConfirmDeleteUserDialog(bool isYes);

	void DoRenameUserDialog(const SexyString &theName);

	void FinishRenameUserDialog(bool isYes);

	void FinishNameError(int theId);

	void FinishRestartConfirmDialog();

	void DoConfirmSellDialog(const SexyString &theMessage);

	void DoConfirmPurchaseDialog(const SexyString &theMessage);

	void FinishTimesUpDialog();

	/// @brief Destroy the Board
	void KillBoard();

	/// @brief Create a new Board
	void MakeNewBoard();

	void StartPlaying();

	bool TryLoadGame();

	void NewGame();

	void PreNewGame(GameMode theGameMode, bool theLookForSavedGame);

	/// @brief Open the GameSelector
	void ShowGameSelector();

	/// @brief Close the GameSelector
	void KillGameSelector();

	/// @brief Open the Award Screen
	/// @param theAwardType The type of award to present (see AwardType enum)
	void ShowAwardScreen(AwardType theAwardType);

	/// @brief Close the Award Screen
	void KillAwardScreen();

	/// @brief Open the SeedChooser
	void ShowSeedChooserScreen();

	/// @brief Close the SeedChooser
	void KillSeedChooserScreen();

	/// @brief Return to the GameSelector from the Board
	void DoBackToMain();

	/// @brief Do the Board exit confirmation dialog
	void DoConfirmBackToMain();

	/// @brief Open the Options Menu
	/// @param theFromGameSelector Did we open from the GameSelector
	void DoNewOptions(bool theFromGameSelector);

	/// @brief Attempt to Register (Unimplemented)
	void DoRegister();

	/// @brief Handle the Registering error (Unimplemented)
	void DoRegisterError();

	/// @brief Can open the Registering Dialog (Unimplemented)
	/// @return True if we can register
	bool CanDoRegisterDialog();

	/// @brief Write the PlayerInfo to Disk
	/// @return Always true
	bool WriteCurrentUserConfig();

	/// @brief Open the Registering Dialog () (Unimplemented)
	void DoNeedRegisterDialog();

	/// @brief Open the Continue Dialog
	void DoContinueDialog();

	/// @brief Open the Pause Dialog
	void DoPauseDialog();

	void FinishModelessDialogs();

	virtual Dialog *DoDialog(int theDialogId,
							 bool isModal,
							 const SexyString &theDialogHeader,
							 const SexyString &theDialogLines,
							 const SexyString &theDialogFooter,
							 int theButtonMode);

	virtual Dialog *DoDialogDelay(int theDialogId,
								  bool isModal,
								  const SexyString &theDialogHeader,
								  const SexyString &theDialogLines,
								  const SexyString &theDialogFooter,
								  int theButtonMode);

	virtual void Shutdown();

	virtual void Init();

	virtual void Start();

	virtual Dialog *NewDialog(int theDialogId,
							  bool isModal,
							  const SexyString &theDialogHeader,
							  const SexyString &theDialogLines,
							  const SexyString &theDialogFooter,
							  int theButtonMode);

	virtual bool KillDialog(int theDialogId);

	virtual void ModalOpen();

	virtual void ModalClose();

	virtual void PreDisplayHook();

	virtual bool ChangeDirHook(const char *theIntendedPath);

	virtual bool NeedRegister();

	virtual void UpdateRegisterInfo();

	virtual void ButtonPress(int theId);

	virtual void ButtonDepress(int theId);

	virtual void UpdateFrames();

	virtual bool UpdateApp();

	bool IsAdventureMode();

	bool IsSurvivalMode();

	bool IsContinuousChallenge();

	bool IsArtChallenge();

	bool NeedPauseGame();

	virtual void ShowResourceError(bool doExit = false);

	void ToggleSlowMo();

	void ToggleFastMo();

	void PlayFoley(FoleyType theFoleyType);

	void PlayFoleyPitch(FoleyType theFoleyType, float thePitch);

	void PlaySample(int theSoundNum);

	void FastLoad(GameMode theGameMode);

	static SexyString GetStageString(int theLevel);

	void KillChallengeScreen();

	void ShowChallengeScreen(ChallengePage thePage);

	ChallengeDefinition &GetCurrentChallengeDef();

	void CheckForGameEnd();

	virtual void CloseRequestAsync();

	bool IsChallengeWithoutSeedBank();

	AlmanacDialog *DoAlmanacDialog(SeedType theSeedType = SeedType::SEED_NONE, ZombieType theZombieType = ZombieType::ZOMBIE_INVALID);

	bool KillAlmanacDialog();

	int GetSeedsAvailable();

	Reanimation *AddReanimation(float theX, float theY, int theRenderOrder, ReanimationType theReanimationType);

	TodParticleSystem *AddTodParticle(float theX, float theY, int theRenderOrder, ParticleEffect theEffect);

	ParticleSystemID ParticleGetID(TodParticleSystem *theParticle);

	TodParticleSystem *ParticleGet(ParticleSystemID theParticleID);

	TodParticleSystem *ParticleTryToGet(ParticleSystemID theParticleID);

	ReanimationID ReanimationGetID(Reanimation *theReanimation);

	Reanimation *ReanimationGet(ReanimationID theReanimationID);

	Reanimation *ReanimationTryToGet(ReanimationID theReanimationID);

	void RemoveReanimation(ReanimationID theReanimationID);

	void RemoveParticle(ParticleSystemID theParticleID);

	StoreScreen *ShowStoreScreen();

	void KillStoreScreen();

	bool HasSeedType(SeedType theSeedType);

	bool SeedTypeAvailable(SeedType theSeedType);

	void EndLevel();

	inline bool IsIceDemo()
	{
		return false;
	}

	bool IsShovelLevel();

	bool IsWallnutBowlingLevel();

	bool IsMiniBossLevel();

	bool IsSlotMachineLevel();

	bool IsLittleTroubleLevel();

	bool IsStormyNightLevel();

	bool IsFinalBossLevel();


	bool IsBungeeBlitzLevel();

	static SeedType GetAwardSeedForLevel(int theLevel);

	SexyString GetCrazyDaveText(int theMessageIndex);

	bool CanShowAlmanac();

	bool IsNight();

	bool CanShowStore();

	bool HasBeatenChallenge(GameMode theGameMode);

	PottedPlant *GetPottedPlantByIndex(int thePottedPlantIndex);

	static bool IsSurvivalNormal(GameMode theGameMode);

	static bool IsSurvivalHard(GameMode theGameMode);

	static bool IsSurvivalEndless(GameMode theGameMode);

	bool HasFinishedAdventure();

	bool IsFirstTimeAdventureMode();

	bool CanSpawnYetis();

	void CrazyDaveEnter();

	void UpdateCrazyDave();

	void CrazyDaveTalkIndex(int theMessageIndex);

	void CrazyDaveTalkMessage(const SexyString &theMessage);

	void CrazyDaveLeave();

	void DrawCrazyDave(Graphics *g);

	void CrazyDaveDie();

	void CrazyDaveStopTalking();

	void PreloadForUser();

	int GetNumPreloadingTasks();

	int LawnMessageBox(int theDialogId,
					   const SexyString &theHeaderName,
					   const SexyString &theLinesName,
					   const SexyString &theButton1Name,
					   const SexyString &theButton2Name,
					   int theButtonMode);

	void ShowCreditScreen();

	void KillCreditScreen();

	void ShowZombatarTOS();

	static SexyString Pluralize(int theCount, const SexyString &theSingular, const SexyString &thePlural);

	int GetNumTrophies(ChallengePage thePage);

	bool EarnedGoldTrophy();

	inline bool IsRegistered()
	{
		return false;
	}

	inline bool IsExpired()
	{
		return false;
	}

	inline bool IsDRMConnected()
	{
		return false;
	}

	bool IsScaryPotterLevel();

	static bool IsEndlessScaryPotter(GameMode theGameMode);

	bool IsSquirrelLevel();

	bool IsIZombieLevel();

	bool CanShowZenGarden();

	static SexyString GetMoneyString(int theAmount);

	bool AdvanceCrazyDaveText();

	bool IsWhackAZombieLevel();

	void BetaSubmit(bool theAskForComments);

	void BetaRecordLevelStats();

	void UpdatePlayTimeStats();

	void BetaAddFile(std::list<std::string> &theUploadFileList, std::string theFileName, std::string theShortName);

	bool CanPauseNow();

	bool IsPuzzleMode();

	bool IsChallengeMode();

	static bool IsEndlessIZombie(GameMode theGameMode);

	void CrazyDaveDoneHanding();

	inline SexyString GetCurrentLevelName()
	{
		return "Unknown";
	}

	int TrophiesNeedForGoldSunflower();

	int GetCurrentChallengeIndex();

	void LoadGroup(const char *theGroupName, int theGroupAveMsToLoad);

	void TraceLoadGroup(const char *theGroupName, int theGroupTime, int theTotalGroupWeigth, int theTaskWeight);

	void CrazyDaveStopSound();

	bool IsTrialStageLocked();

	void FinishZenGardenToturial();

	bool UpdatePlayerProfileForFinishingLevel();

	bool SaveFileExists();

	bool CanDoPinataMode();

	bool CanDoDanceMode();

	bool CanDoDaisyMode();

	virtual void SwitchScreenMode(bool wantWindowed, bool is3d, bool force = false);

	static void CenterDialog(Dialog *theDialog, int theWidth, int theHeight);

};

SexyString LawnGetCurrentLevelName();
bool LawnGetCloseRequest();
bool LawnHasUsedCheatKeys();
void BetaSubmitFunc();

extern bool (*gAppCloseRequest)();
extern bool (*gAppHasUsedCheatKeys)();
extern SexyString (*gGetCurrentLevelName)();

extern bool gIsPartnerBuild;
extern bool gFastMo;
extern bool gSlowMo;
extern LawnApp *gLawnApp;
extern int gSlowMoCounter;

#endif // __LAWNAPP_H__