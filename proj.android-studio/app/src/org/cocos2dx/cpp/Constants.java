package org.cocos2dx.cpp;

//import com.badlogic.gdx.Application;

public class Constants {

//    public static final int LOG_CONFIG = Application.LOG_DEBUG;
    public static final boolean HAS_TEST_SERVER = true;
	/**
	 * Bật cờ này thành true khi build bản release macos để check receipt
	 */
    public static final boolean CHECK_MAC_RECEIPT = false;

	public static final boolean GIAI_DAU_BUILD = false;

	public static final boolean HIDE_CHANGE_AVATAR_ON_IPAD_MINI1 = true;

	public static final boolean TEST_PARSE_CRASH_REPORT = false;
	public static final boolean HAVE_CHIEU_BI = false;

	/**
	 * Nhung tham so dung de thuc hien load resource dong.
	 */
	public static final String SCREEN_SIZE240320 = "240320";
	public static final String SCREEN_SIZE320480 = "320480";
	public static final String SCREEN_SIZE480800 = "480800";
	public static final String SCREEN_SIZE640960 = "640960";

	/*
	 * Parse Setting
	 */
	public static final String PARSE_APP_ID = "DKOzf6Fumcpfq0NdATk3rhuM4TUyINrpR9RcXEKF";
	public static final String PARSE_CLIENT_ID = "JDWkiVhqpbhLUhlHYgluGDwDZn8CcSQpsXfNApnq";
	public static final String PARSE_WINFREE_BACKGROUND = "imgWinFreeBG";
	public static final String PARSE_INSTALLATION_URL_LOCAL = "http://10.8.14.79:8090/install/new_install";
	public static final String PARSE_INSTALLATION_URL_RELEASE = "http://av.iwin.me/install/new_install";
	public static final String USER_INSTALLATION_CLASS_NAME = "User_Installation";
	public static final String USER_INSTALLATION_USER_KEY = "user";
	public static final String USER_INSTALLATION_INSTALLATION_KEY = "installation";

	/*
	 * Key để gửi installation lên server mình
	 */
	public static final String KEY_VALUE = "4IOXsYqdnTqCg";

	/**
	 * Configure version for Desktop and Html5.
	 */
	public static final String DESKTOP_HTML5_VERSION = "5.1.6";
	/**
	 * BUILD NUMBER
	 */
    public static final int BUILD_NUMBER = 20;


	// Constants support countly.
	public static final String CountlyHost = "http://countly.iwin.me";
	public static final String CountlyAppKey = "d63dd2c4e075961fa65e37674a109cfdb7d7eeab";
	public static final String CountlyAppId = "5461d3f93d7bdbdf5f000001";

	// Key check valid key.
	public static final String DEBUG_HASHKEY = "d/dcfPbXv8TIdi9GG8yC0xET1Jg=";
	public static final String RELEASE_HASHKEY = "k6E2FReCYNsmKAOAljxh8ZyE2Uk=";

	public static final String GOOGLE_PLAY_KEY = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAkQNP6ZM/Ydid/PojmJhKEhPSSSN9HEIDTXSUFFgAVRFGE9QVApbyYX1DbPSvE2Fk/T9XXMxDZQ0l3zTgm+mbCzsuv0Gw1rh/HQ6twr+2X1jJyxFyblFaeiqX909PmWNFC4dm5mEEmEDbZ/PT+OepUgqyJB5putt6zBOPzG7lLCnD2TRkXw9ze+L/roxdknc9RPw3tmMtXCxSktib31Z9vUo0rRmr5eEZtSYCbfXeRrXXwwMFL7xbpbEEK1UaDUeH2c3QMUwN+ji6/pA2CrWTzIJP1hAaUzH3/Uv3fBhZofeyoYqb87D6xftHf6Ir29FTYtaS4jVz6auyiXLjpAd2IQIDAQAB";
	public static final String GOOGLE_PLAY_KEY_FOR_IWIN_VN_M_P592 = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAlKuHlbO86GwIBB9UrdgnG0H2F/wkfUsD7sC9sQkFt08nmf920jXL2T16T458Qy42PfpKPkgwDkrB6lV68rVySqmlvtZxXem5AkLnvPM/up8QxiV3jgQ6DED7xuwzVKZxmPr0Ys5APeJtQrJcRXQI3UhNsba7zCyV00sKjUjUhV9BP7HkzfrpS3n08CN9UlgG6cKbh5sEB3cCvEhbl4simPCcRrwXJB7zTUjl3xTzqW7UNUlS1q8cRoMADC9HnKoYk6g/1vpG+SopdGG/I+yyVqFUipjne107Uiz8qlkYk30kxtqAxGirec0A0spWSGJwRYGBRWdBAtTJO4VCVZQ97QIDAQAB";
	public static final String GOOGLE_PLAY_KEY_FOR_IWIN_VN_M_P593 = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAh5qG3djiX47zgrlImLPIXiDdfDK/LLkiNbeGykj/xLrXSS7nUEgGAoK4nA6A8mRr2CWPAH/oQ+UzIlxW89vNLjtY+cBIQSVlnxwZmG+6d/ypTvLlBEC7Yp4Eh8fCBw8ZWqM9dyUZShlmcw5VbkiTv1LDufzifAdWFdaZ681xY1LOT5gUsHIrgkFbZm8hzwVdwidY9JYZENoXEHYsXh4Zvt6MOXUuX3c7rc45/0t8b20WLOqLfr0pirHIKMxvCnIrzL2heE/8MyorLabi+T0TV9knIsxBdeMIVscr1LreaoF6HqJR7EiMdDMORd/Kqh66VFtUw0Ix2aAFDFQTACVgnwIDAQAB";
	public static final String GOOGLE_PLAY_KEY_FOR_IWIN_VN_M = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAzPnjuLvl07laEuJIeabUGiaS/RgAzhfgUl1kn1nUMx/dlYR03RGzoZGUH12i2RA0zHdnzf9gbghYNVL2sgf1tBq4+zZXsznmVeNiIF4zBM4mI11rk6iYF0u0dWayKyZULF3ndZPtl45osbXP9ADoCKITOtSxy6KfyeEZ+Wtsln4CdZ6RawtqABOztyCjJV/7fI1NAPSSQsnVeeDuw/0v8ezSFQjq+OdB8JdqRQVmk+TRNCNJU4c1kJcKKokMdW3ejzO5xo1MqYyqm+bv324sUIw8Y0bjyMS9aqDSFX0O68KENzDjVnPpETIexq99udu0JoMx0bboQDKKZzTbdoCJcwIDAQAB";

	// Mint Key
	public static final String IOS_BUGSENSE_KEY = "25013548";
	public static final String ANDROID_BUGSENSE_KEY = "f2c2d2f4";

	public static final String GAI = "UA-65027580-1";
	// Facebook App ID.
	public static final String FACEBOOK_APP_ID = "315837181868526";
	public static final String FACEBOOK_APP_ID_FOR_SALE = "304571766370555";
	public static final String FACEBOOK_APP_ID_FOR_SDKLIB = "1635025826732920";
	public static final String FACEBOOK_APP_ID_FOR_P592 = "223727234642912";
	public static final String FACEBOOK_APP_ID_FOR_P593 = "160368184348784";

	// Google Plus Public ID
	// Account iwin.vn.full da bi banned.
	// public static final String GOOGLE_PLUS_CLIENT_ID =
	// "721589498812-v1bhplf8vprgreur79skj78s0bibj2pc.apps.googleusercontent.com";
	public static final String GOOGLE_PLUS_CLIENT_ID = "1069937706397-h4t751eck831ojl6qq4sfssklg05dta1.apps.googleusercontent.com";//
	public static final String REVERSE_GOOGLE_PLUS_CLIENT_ID = "com.googleusercontent.apps.721589498812-v1bhplf8vprgreur79skj78s0bibj2pc";
	public static final String GOOGLE_PLUS_CLIENT_ID_FOR_SALE = "721589498812-d747b79hmaomqmir0bsug74ekhos14fj.apps.googleusercontent.com";
	public static final String GOOGLE_PLUS_CLIENT_ID_FOR_SDKLIB = "699153824643-dqle7ckjtkmoeg2teiv2km1d8pgv96gu.apps.googleusercontent.com";
	public static final String REVERSE_GOOGLE_PLUS_CLIENT_ID_FOR_SDKLIB = "com.googleusercontent.apps.699153824643-dqle7ckjtkmoeg2teiv2km1d8pgv96gu";

	// AppsFlyerConfig iOS
	public static final String APPS_FLYER_DEV_KEY_IOS = "DYFqfjH7kT482Qmyh6AWFG";
	public static final String APPLE_APP_ID_IOS = "1119897879";

	// Appsflyer Android
	public static final String APPS_FLYER_DEV_KEY_ANDROID = "DYFqfjH7kT482Qmyh6AWFG";// lan
																						// doi
																						// gan
																						// nhat
																						// 21/9/2016
	// DYFqfjH7kT482Qmyh6AWFG// y9oZcGZJWxr4KgEUERyk7S

	// InMobiManager iOS Advertiser
	public static final String APP_ID_INMOBI_IOS = "e34e7163a60344b9bcd4c5abf38a5b1d";

	// MobileAppTracking iOS
	public static final String ADVERTISER_ID_IOS = "17334";
	public static final String CONVERSION_KEY_IOS = "be3d19787ad17005ca720c2828c27e99";

	// [ACTConversionReporter
	// reportWithConversionID:@"962928602"label:@"PHadCPaj8lwQ2r-UywM"
	// value:@"1.00" isRepeatable:NO];
	// GoogleConversionTracking iOS
	public static final String CONVERSION_ID_IOS = "962928602";
	public static final String LABEL_CONVERSION_IOS = "Pz4PCLupt2gQ2r-UywM";

	// password cấm
	public static final String[] listNotPassword = { "123456", "pa#sword", "12345678", "1234", "123456789", "12345",
			"dragon", "qwerty", "696969", "qwe123", "123abc", "123654", "987654321", "654321", "111111", "222222",
			"333333", "abc123", "444444", "555555", "666666", "777777", "888888", "999999", "000000", "qaz123",
			"123qaz", "aaaaaa", "zzzzzz", "87654321", "batman", "88888888", "999999999", "7777777", "blowjob", "xxxxxx",
			"loveyou", "1234567", "soccer", "killer", "superman", "fuckyou", "121212", "131313", "123123", "chelsea",
			"computer", "hardcore", "arsenal", "forever", "987654", "112233", "11223344", "samsung", "s@msung",
			"iphone", "iphone4", "iphone5", "iphone6" };

	// All Link Define Here.
	public static final String LINK_GET_REVIEW_APPS_INFO = "http://av.iwin.me/wf/help/review_new";
	public static final String LINK_HELP_FOR_REVIEWING = "http://av.iwin.me/wf/help/policy.htm";
	public static final String LINK_TERM = "https://iwin.me/tin-tuc-mobile/2-dieu-khoan-su-dung";
	public static final String LINK_BACKGROUND_WINFREE = "http://av.iwin.me/wf/imgWinFreeBG.png";
	public static final String LINK_CUSTOMER_SERVICE = "http://hotro.iwin.me/login?type=2";
	public static final String LINK_CUSTOMER_SERVICE_FULL = "http://hotro.iwin.me/login?type=1";
	public static final String LINK_WEB = "http://iwin.me";

	// Chat
	public static final int MAX_LENGTH_CHAT = 100;

	// Khoảng thời gian sẽ báo rung khi sắp hết lượt (milisecond)
	public static final int TIME_VIBRATE_CARD_GAME = 5000; // 5s cho game bài
	public static final int TIME_VIBRATE_BOARD_GAME = 10000; // 10s cho game cờ
	/**
	 * thoi gian goi lai ham lay danh sach
	 */
	public static final int TIME_GET_LIST_WAIT = 60;

	// Pixel
	public static final String TRACKING_APP_ID = "570f3a724bd04d9a3778bceb";
	public static final String TRACKING_DOMAIN = "https://engine.itracking.io/";
	public static final String TRACKING_SECRET_KEY = "9cuAprmtyCWYj6";
	public static final String TRACKING_FACEBOOK_ID = "315837181868526";

	public static final String ADWORDS_CONVERSION_ID_M = "962928602";
	public static final String ADWORDS_CONVERSION_LABEL_M = "2k99CPqN-GUQ2r-UywM";

	public static final String ADWORDS_CONVERSION_ID_FULL = "962928602";
	public static final String ADWORDS_CONVERSION_LABEL_FULL = "KBuUCKrTumgQ2r-UywM";

	public static final String ADWORDS_CONVERSION_ID_592 = "962928602";
	public static final String ADWORDS_CONVERSION_LABEL_592 = "Y3bWCNXC_2UQ2r-UywM";

	// OneSignal
	// vn.mecorp.iwin : "c14a1bba-6089-4c32-bf71-252f6c63bfda"
	// vn.iwin.full : "6b9619e8-20bc-4350-813e-2e3f737911b9"
	public static final String ONESIGNAL_APP_ID_VN_MECORP_IWIN = "c14a1bba-6089-4c32-bf71-252f6c63bfda";
	public static final String ONESIGNAL_APP_ID_VN_IWIN_FULL = "cea95ff6-d71b-47cf-aafe-90c83d50ccd5";

	public static final int BASE_MONEY = 1;
	public static final int RUBY_MONEY = 2;

	public static final String BUNDLE_ID_ANDROID_M = "iwin.vn.m";

	public static final String TRACKING_PURCHASE_CANCEL = "iwin.appevent.purchasecancel";
	public static final String TRACKING_PURCHASE_CANCEL1 = "iwin.appevent.purchasecancel1";
	public static final String TRACKING_INITIATED_CHECKOUT = "iwin.inappevent.initiatedcheckout";
	public static final String TRACKING_CLICK_SIGNUP = "iwin.inappevent.signup";
	public static final String TRACKING_CLICK_EVENT = "iwin.inappevent.clickevent";
	public static final String TRACKING_LAST_LOCATION = "iwin.inappevent.lastlocation";
	public static final String TRACKING_OPEN_PUSHNOTIFICATION = "iwin.inappevent.openpushnotification";
	public static final String TRACKING_CLICK_SHARE_EVENT = "iwin.inappevent.share";
	public static final String TRACKING_CLICK_INVITE = "iwin.inappevent.invite";

	/**
	 * Android list mail package
	 */
	public static final String LIST_APP_EMAIL_PACKAGE_ANDROID = "com.google.android.gm,com.yahoo.mobile.client.android.mail,com.microsoft.office.outlook,com.zoho.mail,ru.yandex.mail,de.gmx.mobile.android.mail";
	public static final String LIST_APP_EMAIL_NAMEAPP_ANDROID = "Gmail,Yahoo,OutLook,Zoho,Yandex,Gmx";
	public static final String SMS_DEFAULT_PACKAGE_ANDROID = "com.android.mms";
	public static final String SMS_DEFAULT_PACKAGE_IOS = "sms:";

	/**
	 * Link App Google Authentication for IOS
	 */
	public static final String LINK_IOS_APP_GOOGLE_AUTHENTICATION = "itms://itunes.apple.com/us/app/google-authenticator/id388497605?mt=8";
	public static final String URL_SCHEME_IOS_GOOGLE_AUTHENTICATION = "googleauthenticator://";

	public static final String LINK_ANDROID_APP_GOOGLE_AUTHENTICATION = "https://play.google.com/store/apps/details?id=com.google.android.apps.authenticator2&hl=en";

	/**
	 * Define tên biến cho việc đá app IOS , vn.iwin.full://screenID=10&gameID=10
	 */
	public static final String screen_ID = "screenID";
	public static final String game_ID = "gameID";

    public static final byte[] VERSION_ENCODE = new byte[] {0,0,0,5,-104,-78,-126,53,121,-125,-56,70};
    public static final String GETOS_ANDROID = "android";

}
