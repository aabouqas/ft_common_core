"use client"
import { Cog, CheckCircle2 } from "lucide-react"
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select"
import {useState, useEffect, useContext} from "react"
import { useTranslation } from "react-i18next"
import Loading from "@/app/(app)/components/Loading";
import {fetchWithToken} from "@/app/Utils";
import {baseUrl, useUser} from "@/app/types";
import {UserContext} from "@/app/types";

export default function GeneralSettings() {
  const {t, i18n} = useTranslation();
  const [notifications, setNotifications] = useState(false)
  const [isSaving, setIsSaving] = useState(false)
  const [saved, setSaved] = useState(false)
  const [bio, setBio] = useState("");
  const [language, setLanguage] = useState("");

  const {user} = useUser();

  useEffect(() => {
    setBio(user.bio);
    setLanguage(user.language);
    i18n.changeLanguage(user.language);
  }, [user]);


  const handleLanguageChange = async (lang: string) => {
    i18n.changeLanguage(lang);
    setLanguage(lang);
    // Update localStorage so it persists across refreshes
    if (typeof window !== "undefined") {
      localStorage.setItem("language", lang);
    }
  };

  const handleSave = async () => {
    if (isSaving) return
    setIsSaving(true)
    setSaved(false)

    try {
      const response = await fetchWithToken(
          `${baseUrl}/api/settings/privacy`,
          {
            method: 'PUT',
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify({
              bio: bio,
              language: language
            })
          }
      );
      if (response.status !== 201) {
        setIsSaving(false)
      }
      if (response.status === 201) {
        setTimeout(() => {
          setIsSaving(false)
          setSaved(true)
          setTimeout(() => setSaved(false), 2500)
        }, 800);
      }
    } catch {
      setIsSaving(false)
    }
  }

  return (
    <div className="rounded-lg flex-1 border bg-[#081C29]/80 border-[#21364a] hover:border-[#23ccdc]/30 transition-all duration-300 h-full flex flex-col">
      <div className="p-6 flex flex-col h-full">
        <div className="flex items-center mb-6">
        <div
          className="p-2 mr-2 rounded-lg border" style={{ backgroundColor: "#00F5FF1A", borderColor: "#00F5FF8A"}}>
          <Cog className="h-5 w-5 text-[#23ccdc]" />
        </div>
          <h2 className="text-xl font-semibold text-white">{t("game.general")}</h2>
        </div>

        {/* Form fields section - takes available space */}
        <div className="space-y-4 flex-grow">
          <div>
            <label className="block text-[#a4aca7] text-sm mb-2">{t("game.language")}</label>
            <Select
              defaultValue="english"
              value={i18n.language} onValueChange={handleLanguageChange}>
              <SelectTrigger className="bg-[#113A4B]/50 border-[#498195]/30 text-white focus:border-[#23ccdc] focus:ring-0 focus:ring-offset-0 data-[state=open]:border-[#23ccdc]">
                <SelectValue />
              </SelectTrigger>
              <SelectContent className="bg-[#081C29] border-[#21364a]">
                <SelectItem
                   value="en" className="text-white hover:bg-[#113A4B]/50">
                  {t("game.english")}
                </SelectItem>
                <SelectItem
                  value="am" className="text-white hover:bg-[#113A4B]/50">
                  {t("game.tamazight")}
                </SelectItem>
                <SelectItem
                  value="ar" className="text-white hover:bg-[#113A4B]/50">
                  {t("game.arabic")}
                </SelectItem>
              </SelectContent>
            </Select>
          </div>
        </div>

        {/* Button section - sticks to bottom */}
        <div className="flex items-center justify-between mt-6">
          {saved && (
            <div className="flex items-center text-green-400 text-sm">
              <CheckCircle2 className="h-4 w-4 mr-1" />
              <span>{t("settingsSavedSuccessfully")}</span>
            </div>
          )}
          <button
            onClick={handleSave}
            disabled={isSaving}
            className="ml-auto bg-[#00A3FF]/50 hover:bg-[#00A3FF]/80 disabled:opacity-60 text-white px-10 py-2 rounded-lg transition-all duration-300"
          >
            <Loading isloading={isSaving} label={t("save")}/>
          </button>
        </div>
      </div>
    </div>
  )
}