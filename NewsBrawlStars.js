const puppeteer = require('puppeteer-core');
const fs = require('fs');
const getCurrentLine = require('get-current-line').default;
const { execFileSync } = require('child_process');

const data = fs.readFileSync('aviso.bz.cookies.json');
const cookies = JSON.parse(data.toString());

function randomInteger(min, max) {
  let rand = min - 0.5 + Math.random() * (max - min + 1);
  return Math.round(rand);
}

function delay(time) {
   return new Promise(function(resolve) {
       setTimeout(resolve, time*1000)
   });
}

function delay2(time) {
   return new Promise(function(resolve) {
       setTimeout(resolve, time)
   });
}

let ext = '/home/user/aviso/extensions/1.42.4_0';

(async () => {
  const browser = await puppeteer.launch({
    headless: false,
    defaultViewport: null,
    executablePath: '/usr/bin/chromium',
devtools: false,
    args: [
'--start-maximized',
//'--user-agent="Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.88 Safari/537.36"',
//`--disable-extensions-except=${ext}`,
//`--load-extension=${ext}`
 ]
  });

  const page = await browser.newPage();
  await page.setDefaultNavigationTimeout(0);

  let newPage;

  await page.setCookie(...cookies);
  await page.goto('https://aviso.bz/work-youtube', {waitUntil: 'networkidle0'});
//await delay(1000);
  let c = 0;
  while(true) {

  if(c == 100) {
    await page.reload({ waitUntil: ["networkidle0", "domcontentloaded"] });
    c = 0;
  }

let t = await page.$('[id^="ads-link-"]');
if(t == null) {
console.log('wait new tasks...');
await delay(10);
await page.reload({ waitUntil: ["networkidle0", "domcontentloaded"] });
c = 0;
continue;
}
let tt = await t.evaluate((q) => getComputedStyle(q).display);
if(tt == 'none') {
console.log('del inactive')
page.evaluate(q => { document.querySelector('[id^="ads-link-"]').remove(); })
continue;
}

let tr = await page.$('tr[class^="ads_"]');
let span = await tr.$('[onclick^="funcjs[\'start_youtube"]');
let title = await span.evaluate(el => el.textContent.trim());
console.log('title: \''+title+'\'');
let sec = await tr.$('td[align="right"] span[class="serf-text"]');
let secs = await sec.evaluate(el => el.textContent.trim());
console.log('sec: ' + secs.split(' ')[0]);

let newPagePromise = new Promise(x => browser.once('targetcreated', target => x(target.page())));

//await page.waitForSelector('tr[class^="ads_"] span[onclick^="funcjs[\'start_youtube"]');
//let x = await page.$('tr[class^="ads_"] span[onclick^="funcjs[\'start_youtube"]');
//console.log(x.click);
await page.waitForTimeout(2000);
try {
await page.click('tr[class^="ads_"] span[onclick^="funcjs[\'start_youtube"]');
}
catch(e) {
console.log('error! del item');
await page.evaluate(() => {
    document.querySelector('tr[class^="ads_"]').remove()
  });
continue; } await page.waitForSelector('span[onclick^="funcjs[\'open_window\']"]', { timeout: 60000 }); await delay2(randomInteger(700, 2000)); await page.click('span[onclick^="funcjs[\'open_window\']"]'); newPage = await newPagePromise; await newPage.bringToFront(); const userAgent = await newPage.evaluate(() => navigator.userAgent ); console.log(userAgent) //let pages = await browser.pages(); console.log('> '+newPage.url()); await newPage.waitForSelector('tr[id="timer-tr-block"]', { timeout: 200000 }); await delay(randomInteger(2, 4)); console.log('yt click'); const frame = await newPage.waitForSelector('iframe'); let rect = await newPage.evaluate(el => { let {width, height} = el.getBoundingClientRect(); return {width, height}; }, frame); await newPage.mouse.click(rect.width / 2, rect.height / 2); //execFileSync('xdotool', ['mousemove', '960', '611']); //execFileSync('xdotool', ['click', '1']); console.log('waiting'); await newPage.waitForSelector('a[href=""]', { timeout: 200000 }); console.log('ok'); await delay2(randomInteger(900, 1500)); //console.log('> '+newPage.url()); await newPage.close(); await delay2(500); await page.bringToFront(); await page.evaluate(() => { document.querySelector('tr[class^="ads_"]').remove() }); await delay(randomInteger(1, 3)); console.log('c: '+ ++c +"\n"); } await browser.close(); })();
