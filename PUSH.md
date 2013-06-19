# 如何使用AVOS  Cloud的Push功能

本文将向您简单介绍如何使用AVOS cloud的推送功能。


# 登录到apple的 Developer Program Portal

创建您的app id，并且选择允许push。并且确保您的apple id不含有通配符

# 下载您的push证书并且转换成.p12格式

# 生成您的provision profile

# 


# Choose App IDs from the menu on the right (or click here)

# Create an App ID without a wildcard. For example 3L223ZX9Y3.com.armiento.test

# Click the Configure link next to this App ID and then click on the button to start the wizard to generate a new Development Push SSL Certificate (Apple Documentation: Creating the SSL Certificate and Keys)

# Download this certificate and double click on aps_developer_identity.cer to import it into your Keychain

# Launch Keychain Assistant (located in Application, Utilities or search for it with Spotlight) and click on My Certificates on the left

# Expand Apple Development Push Services and select Apple Development Push Services AND your private key (just under Apple Development Push Services)
Right-click and choose "Export 2 elements..." and save as server_certificates_bundle_sandbox.p12 (don't type a password).
