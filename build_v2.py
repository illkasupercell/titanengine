def res_horizontal(self, btn):
        self.im = Image.open(self.new_img)
        if btn.text() == "320x240":
            self.new_im = self.im.resize((320, 240))
        elif btn.text() == '1024x600':
            self.new_im = self.im.resize((1024, 600))
        elif btn.text() == '1280x720':
            self.new_im = self.im.resize((1280, 720))
        elif btn.text() == '1440x900':
            self.new_im = self.im.resize((1440, 900))
        elif btn.text() == '1600x1024':
            self.new_im = self.im.resize((1600, 1024))
        elif btn.text() == '1920x1080':
            self.new_im = self.im.resize((1920, 1080))
        elif btn.text() == '2048x1536':
            self.new_im = self.im.resize((2048, 1536))
        elif btn.text() == '2560x1440':
            self.new_im = self.im.resize((2560, 440))
        elif btn.text() == '3840x2160':
            self.new_im = self.im.resize((3840, 2160))
        elif btn.text() == '4096x2160':
            self.new_im = self.im.resize((4096, 2160))
        elif btn.text == '800x480':
            self.new_im = self.im.resize((800, 480))

        self.new_im.save(self.new_img)

    def res_vertical(self, btn):
        self.im = Image.open(self.new_img)
        if btn.text() == '240x320':
            self.new_im = self.im.resize((240, 320))
        elif btn.text() == '480x800':
            self.new_im = self.im.resize((480, 800))
        elif btn.text() == '600x1024':
            self.new_im = self.im.resize((600, 1024))
        elif btn.text() == '720x1280':
            self.new_im = self.im.resize((720, 1280))
        elif btn.text() == '900x1440':
            self.new_im = self.im.resize((900, 1440))
        elif btn.text() == '1024x1600':
            self.new_im = self.im.resize((1024, 1600))
        elif btn.text() == '1080x1920':
            self.new_im = self.im.resize((1080, 1920))
        elif btn.text() == '1536x2048':
            self.new_im = self.im.resize((1536, 2048))
        elif btn.text() == '1440x2560':
            self.new_im = self.im.resize((1440, 2560))
        elif btn.text() == '2160x3840':
            self.new_im = self.im.resize((2160, 3840))
        elif btn.text() == '2160x4096':
            self.new_im = self.im.resize((2160, 4096))

        self.new_im.save(self.new_img)

    def res_square(self, btn):
        self.im = Image.open(self.new_img)
        if btn.text() == '320x320':
            self.new_im = self.im.resize((320, 320))
        elif btn.text() == '800x800':
            self.new_im = self.im.resize((800, 800))
        elif btn.text() == '1280x1280':
            self.new_im = self.im.resize((1280, 1280))
        elif btn.text() == '1024x1024':
            self.new_im = self.im.resize((1024, 1024))
        elif btn.text() == '1600x1600':
            self.new_im = self.im.resize((1600, 1600))
        elif btn.text() == '1440x1440':
            self.new_im = self.im.resize((1440, 1440))
        elif btn.text() == '1920x1920':
            self.new_im = self.im.resize((1920, 1920))
        elif btn.text() == '2048x2048':
            self.new_im = self.im.resize((2048, 2048))
        elif btn.text() == '3840x3840':
            self.new_im = self.im.resize((3840, 3840))
        elif btn.text() == '2560x2560':
            self.new_im = self.im.resize((2560, 2560))
        elif btn.text() == '4096x4096':
            self.new_im = self.im.resize((4096, 4096))

        self.new_im.save(self.new_img)
