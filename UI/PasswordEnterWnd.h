#ifndef _PasswordEnterDialog_h_
#define _PasswordEnterDialog_h_

#include <GG/Layout.h>

#include "CUIWnd.h"
#include "CUIControls.h"

class PasswordEnterWnd : public CUIWnd {
public:
    /** \name Structors */ //@{
    PasswordEnterWnd();
    void CompleteConstruction() override;
    //@}

    //! \name Mutators
    //!@{
    void ModalInit() override;

    void KeyPress(GG::Key key, std::uint32_t key_code_point, GG::Flags<GG::ModKey> mod_keys) override;
    //!@}

    /** \name Accessors */ //@{
    /** returns a the player's name (.first) and the location of the server (.second -- IP address or name), or "" if none was selected */
    const std::pair<std::string, std::string>& Result() const;
    //@}

protected:
    GG::Rect CalculatePosition() const override;

private:
    std::shared_ptr<CUIEdit>            m_player_name_edit;
    std::shared_ptr<CUIEdit>            m_password_edit;
    std::shared_ptr<CUIButton>          m_ok_bn;
    std::shared_ptr<CUIButton>          m_cancel_bn;
};

#endif // _PasswordEnterDialog_h_


