package com.itheima.srevice.impl;

import com.itheima.dao.IAccountDao;
import com.itheima.domain.Account;
import com.itheima.srevice.IAccountService;
import java.util.List;
/**
 * 账户的业务层实现类
 */
public class AccountServiceImpl implements IAccountService {

    private IAccountDao accountDao;

    public void setAccountDao(IAccountDao accountDao) {
        this.accountDao = accountDao;
    }

    @Override
    public List<Account> findAllAccount() {
        return accountDao.findAllAccount();
    }

    @Override
    public Account findAccountById(Integer AccountId) {
        return accountDao.findAccountById(AccountId);
    }

    @Override
    public void saveAccount(Account account) {
        accountDao.saveAccount(account);
    }

    @Override
    public void updateAccount(Account account) {
        accountDao.updateAccount(account);
    }

    @Override
    public void deleteAccount(Integer accoountId) {
        accountDao.deleteAccount(accoountId);
    }

    @Override
    public void transfer(String sourceName, String targetName, Float money) {
        //1.根据名称查询转入账户
        Account source = accountDao.findAccountByName(sourceName);
        //2.根据名称查询转出账户
        Account target = accountDao.findAccountByName(targetName);
        //3.转出账户减钱
        source.setMoney(source.getMoney()-money);
        //4.转入账户加钱
        target.setMoney(target.getMoney()+money);
        //5.更新转出账户
        accountDao.updateAccount(source);
        //6.更新转入账户
        accountDao.updateAccount(target);
    }
}
